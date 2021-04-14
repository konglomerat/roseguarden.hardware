/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#pragma once

#include "json.hpp"
using namespace nlohmann;

#include <string>
#include <string_view>
#include <optional>
#include <variant>

namespace Network
{

class RoseguardenNodeClient
{
public:
	struct Settings_t
	{
		std::string serverURL;
		std::string fingerprint;
		std::string authentification;
		std::string nodeName;
		std::string version;
	};

public:
	struct SendIdentification {};
	struct GrandAccess
	{
		std::string message;
		std::string info;
	};
	struct DenyAccess
	{
		std::string message;
		std::string info;
	};
	struct UpdateAssignInfo
	{
		std::string code;
		bool valid;
	};
	struct EmptyAction {};

	using Action_t = std::variant<SendIdentification,GrandAccess,DenyAccess,UpdateAssignInfo,EmptyAction>;

	enum Error_t {OK, NOT_INITIALIZED, NO_RESPONSE, INVALID_RESPONSE};

	using Response_t = std::variant<Action_t,Error_t>;

public:
	static void init(const Settings_t&);
	static Response_t sendStartupRequest();
	static Response_t sendUpdate();
	static Response_t sendNodeIdentification();
	static Response_t sendRequestUserAccess(const std::string_view authenticator, const std::string_view pin);
	static Response_t sendRequestAssignCode(const std::string_view authenticator);

private:
	static std::optional<Action_t> parseResponse(const ordered_json&);
	static bool checkReceivedHeader(const ordered_json&);
	static std::optional<Action_t> parseAction(const ordered_json&);
	static Response_t sendAndReceive(const ordered_json&);

private:
	static ordered_json getRequestHeader();
	static std::optional<ordered_json> sendJSONRequest(ordered_json&);

private:
	static std::string serverURL;
	static std::string fingerprint;
	static std::string authentification;
	static std::string nodeName;
	static std::string version;

	static uint32_t actionId;

	static bool initialized;
};
}
