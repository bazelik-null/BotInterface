//
// Created by niko on 19.10.2025.
//

#ifndef BOTINTERFACE_JSONIO_H
#define BOTINTERFACE_JSONIO_H

#include <nlohmann/json.hpp>

struct Data
{
	bool success{};

	std::string token;
	std::string first;
	std::string second;
	std::string third;
};

class JsonIO
{
	public:
		static bool saveValuesAsJson(Data& data);
		static Data readValuesFromJson();
		static nlohmann::json getValuesAsJson(Data& data);

	private:
		static bool getValue(const nlohmann::json& json, const std::string& key, std::string& value);
};

#endif //BOTINTERFACE_JSONIO_H