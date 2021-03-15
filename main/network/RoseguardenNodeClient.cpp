/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#include "RoseguardenNodeClient.h"
#include "JSONHttpClient.h"

#include "esp_log.h"

static const char *TAG = "RoseguardeNodeClient";

namespace Network
{

std::string RoseguardenNodeClient::serverURL;
std::string RoseguardenNodeClient::fingerprint;
std::string RoseguardenNodeClient::authentification;
std::string RoseguardenNodeClient::nodeName;
std::string RoseguardenNodeClient::version;

uint32_t RoseguardenNodeClient::actionId;

bool RoseguardenNodeClient::initialized = false;

const uint32_t MaxNumbRetries = 5;

void RoseguardenNodeClient::init(const Settings_t& settings)
{
	serverURL = settings.serverURL;
	fingerprint = settings.fingerprint;
	authentification = settings.authentification;
	nodeName = settings.nodeName;
	version = settings.version;

	actionId = 0;
	initialized = true;
}

RoseguardenNodeClient::Response_t RoseguardenNodeClient::sendStartupRequest()
{
	return sendAndReceive(
			{
		{"version",  version},
		{"action",   "registerNodeStartup"},
		{"actionid", actionId}
			});
}

RoseguardenNodeClient::Response_t RoseguardenNodeClient::sendUpdate()
{
	return sendAndReceive(
			{
		{"version",  version},
		{"action",   "requestNodeUpdate"},
		{"actionid", actionId}
			});
}

RoseguardenNodeClient::Response_t RoseguardenNodeClient::sendNodeIdentification()
{
	return sendAndReceive(
			{
		{"version",              version},
		{"action",               "syncNodeIdentification"},
		{"actionid",             actionId},
		{"nodename",             nodeName},
		{"classname",            "Door"},
		{"classworkspace",       "Access"},
		{"classid",              "00:01:AB:EF:19:D8:00:11"},
		{"firmware_version",     "0.1.2"},
		{"firmware_compiled_at", "2007-12-22T18:21:01"},
		{"firmware_flashed_at",  "2007-12-24T11:31:02"},
		{"hardware_version",     "0.1.0"}
			});
}

RoseguardenNodeClient::Response_t RoseguardenNodeClient::sendRequestUserAccess(const std::string_view authenticator, const std::string_view pin)
{
	return sendAndReceive(
			{
		{"version",  version},
		{"action",   "requestUserAccess"},
		{"actionid", actionId},
		{"pin",      pin},
		{"auth_key", authenticator}
			});
}

RoseguardenNodeClient::Response_t RoseguardenNodeClient::sendRequestAssignCode(const std::string_view authenticator)
{
	return sendAndReceive(
			{
		{"version",  version},
		{"action",   "requestAssignCode"},
		{"actionid", actionId},
		{"auth_key", authenticator}
			});
}

RoseguardenNodeClient::Response_t RoseguardenNodeClient::sendAndReceive(const ordered_json& actions)
{
	if (initialized)
	{
		ordered_json jsonRequest(json::value_t::object);
		jsonRequest["header"] = getRequestHeader();

		ordered_json actionsArray;
		actionsArray.emplace_back(actions);

		jsonRequest["actions"] = actionsArray;

		if (auto serverResponse = sendJSONRequest(jsonRequest))
		{
			auto action = parseResponse(*serverResponse);

			if (action)
			{
				return *action;
			}
			else
			{
				return Error_t::INVALID_RESPONSE;
			}
		}
		else
		{
			ESP_LOGE(TAG, "No Response received");
		}

		ESP_LOGE(TAG, "Giving up after %u retries", MaxNumbRetries);

		return Error_t::NO_RESPONSE;
	}
	else
	{
		ESP_LOGE(TAG, "Cannot send because client is not initialized");
		return Error_t::NOT_INITIALIZED;
	}
}

std::optional<RoseguardenNodeClient::Action_t> RoseguardenNodeClient::parseResponse(const ordered_json& data)
{
	if (!data.empty())
	{
		if (checkReceivedHeader(data))
		{
			if (data.contains("actions"))
			{
				json actionsData(json::value_t::array);
				actionsData = data["actions"];

				// The server sends an array of actions in its response
				// We evaluate only the first (and only) one for now.
				auto actionData = actionsData[0];

				return parseAction(actionData);
			}
			else
			{
				ESP_LOGE(TAG, "Response does not contain actions array");
			}
		}
		else
		{
			ESP_LOGE(TAG, "Reponse header invalid");
		}
	}
	else
	{
		ESP_LOGE(TAG, "Received empty response");
	}

	return std::nullopt;
}

std::optional<RoseguardenNodeClient::Action_t> RoseguardenNodeClient::parseAction(const ordered_json& data)
{
	if (!data.empty())
	{
		// TODO: Version is currently ignored

		if (data.contains("action"))
		{
			auto actionName = data["action"].get<std::string>();

			if (actionName == "grandAccess")
			{
				// TODO: parse message and info
				return GrandAccess();
			}

			else if (actionName == "denyAccess")
			{
				//TODO: parse message and info
				return DenyAccess();
			}
			else if (
					actionName == "sendIdentification")
			{
				return SendIdentification();
			}

			else if (actionName == "updateAssignInfo")
			{
				if (data.contains("code") && data.contains("valid"))
				{
					return UpdateAssignInfo
							{
						data["code"].get<std::string>(),
								data["valid"].get<bool>()
							};
				}
				else
				{
					ESP_LOGE(TAG, "UpdateAssignInfo invalid");
				}
			}
			else
			{
				ESP_LOGE(TAG, "Action name '%s' invalid", actionName.c_str());
			}
		}
		else
		{
			ESP_LOGE(TAG, "Action does not contain a name");
		}
	}
	else
	{
		return EmptyAction();
	}

	return std::nullopt;
}


bool RoseguardenNodeClient::checkReceivedHeader(const ordered_json& response)
{
	if (response.contains("header"))
	{
		auto& header = response["header"];

		if (header.contains("version") && header["version"].get<std::string>() == version)
		{
			if (header.contains("target") && header["target"].get<std::string>() == "node")
			{
				if (header.contains("source") && header["source"].get<std::string>() == "server")
				{
					return true;
				}
			}
		}
	}

	return false;
}

ordered_json RoseguardenNodeClient::getRequestHeader()
{
	auto uptimeInSeconds = esp_timer_get_time() / 1000 / 1000;

	ordered_json jsonHeader =
	{
			{"source",           nodeName},
			{"version",          version},
			{"target",           "roseguarden.fabba.space"}, // TODO: This is incorrect
			{"fingerprint",      fingerprint},
			{"authentification", authentification},
			{"uptime",           uptimeInSeconds},
			{"logcounter",       0},
			{"errorcounter",     0},
			{"timestamp",        "2021-01-29T09:46:52.594Z"}
	};

	return jsonHeader;
}

std::optional<ordered_json> RoseguardenNodeClient::sendJSONRequest(ordered_json& jsonRequest)
{
	ESP_LOGD(TAG, "Send %s", jsonRequest.dump(4).c_str());

	auto serverResponse = Network::JSONHttpClient::processRequest(serverURL, jsonRequest);

	actionId++;

	if (serverResponse)
	{
		auto& [code, payload] = *serverResponse;

		ESP_LOGD(TAG, "Server responded with status code %u", code);

		// We don't look at the payload if the status code is not as expected
		if (code == 200)
		{
			return payload;
		}
		else
		{
			ESP_LOGW(TAG, "Server responded with status code %u", code);
		}
	}
	else
	{
		ESP_LOGE(TAG, "Could not process request");
	}

	return std::nullopt;
}

}
