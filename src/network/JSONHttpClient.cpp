/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#include <network/JSONHttpClient.h>

//#define LOG_LOCAL_LEVEL ESP_LOG_DEBUG
#include "esp_log.h"

static const char *TAG = "JSONHttpClient";

#include <cstring>
#include <string>

namespace Network
{

const uint32_t MaximumResponseLengthInBytes = 300;

const uint32_t MaxNumbRetries = 5;

std::string JSONHttpClient::responseBuffer;

std::optional<JSONHttpClient::Response_t> JSONHttpClient::processRequest(std::string_view url, const ordered_json& jsonRequest)
{
	esp_http_client_config_t config;
	std::memset(&config, 0, sizeof(config));

	config.url           = url.data();
	config.event_handler = httpEventHandler;
	config.method        = HTTP_METHOD_POST;

	esp_http_client_handle_t clientHandle = esp_http_client_init(&config);

	esp_http_client_set_header(clientHandle, "Content-Type", "application/json");

	const std::string request = jsonRequest.dump();
	ESP_LOGV(TAG, "Sending json request:\n %s", request.c_str());

	std::optional<Response_t> result = std::nullopt;

	for(uint32_t i = 0; i < MaxNumbRetries; i++)
	{
		esp_http_client_set_post_field(clientHandle, request.c_str(), request.size());
		auto err = esp_http_client_perform(clientHandle);

		if (err == ESP_OK)
		{
			auto statusCode = esp_http_client_get_status_code(clientHandle);
			auto contentLength = esp_http_client_get_content_length(clientHandle);

			ESP_LOGV(TAG, "Request returned with Status = %d, content_length = %d", statusCode, contentLength);

			ordered_json jsonResponse;

			// do not try to parse json for any other status code
			if (statusCode == 200)
			{
				ESP_LOGV(TAG, "Response:\n %s", responseBuffer.c_str());

				if (json::accept(responseBuffer))
				{
					ESP_LOGV(TAG, "Found valid json response");
					jsonResponse = json::parse(responseBuffer);
				}
			}

			result = {statusCode, jsonResponse};

			break;
		}
		else
		{
			ESP_LOGE(TAG, "Cannot send HTTP request");
		}
	}

	esp_http_client_cleanup(clientHandle);
	responseBuffer.clear();

	return result;
}

esp_err_t JSONHttpClient::httpEventHandler(esp_http_client_event_t *evt)
{
	switch(evt->event_id)
	{
	case HTTP_EVENT_ERROR:
		ESP_LOGV(TAG, "HTTP_EVENT_ERROR");
		break;

	case HTTP_EVENT_ON_CONNECTED:
		ESP_LOGV(TAG, "HTTP_EVENT_ON_CONNECTED");
		break;

	case HTTP_EVENT_HEADER_SENT:
		ESP_LOGV(TAG, "HTTP_EVENT_HEADER_SENT");
		break;

	case HTTP_EVENT_ON_HEADER:
		ESP_LOGV(TAG, "HTTP_EVENT_ON_HEADER");
		printf("%.*s", evt->data_len, (char*)evt->data);
		break;

	case HTTP_EVENT_ON_DATA:

		// HTTP 1.1 Chunked responses are not supported
		if (!esp_http_client_is_chunked_response(evt->client))
		{
			ESP_LOGV(TAG, "HTTP_EVENT_ON_DATA, len=%d", evt->data_len);

			if (responseBuffer.size() < MaximumResponseLengthInBytes)
			{
				auto numbBytesToStore = std::min<uint32_t>(MaximumResponseLengthInBytes - responseBuffer.size(), evt->data_len);
				auto eventData = (char*) evt->data;

				responseBuffer.append(eventData, numbBytesToStore);
			}
		}
		else
		{
			ESP_LOGW(TAG, "Ignoring chunked response");
		}
		break;

	case HTTP_EVENT_ON_FINISH:
		ESP_LOGV(TAG, "HTTP_EVENT_ON_FINISH");
		break;

	case HTTP_EVENT_DISCONNECTED:
		ESP_LOGV(TAG, "HTTP_EVENT_DISCONNECTED");
		break;
	}

	return ESP_OK;
}

}
