/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#pragma once

#include "esp_http_client.h"
#include "json.hpp"
using namespace nlohmann;

#include <string_view>
#include <string>
#include <optional>

namespace Network
{

class JSONHttpClient
{
public:
	enum State_t
	{
		ERROR,
		DISCONNECTED,
		CONNECTED
	};
	using Response_t = std::pair<uint32_t, ordered_json>;
	static std::optional<Response_t> processRequest(std::string_view url, const ordered_json& jsonRequest);

public:
	static State_t getState();

private:
	static esp_err_t httpEventHandler(esp_http_client_event_t *evt);
	static std::string responseBuffer;
	static State_t state;
};

}

