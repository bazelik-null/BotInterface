//
// Created by niko on 19.10.2025.
//

#include <headers/io/jsonio.h>
#include <fstream>
#include <iostream>

// TODO: encryption

void JsonIO::saveValuesAsJson(Data data)
{
	const nlohmann::json json = getValuesAsJson(data);

	std::ofstream outFile("settings.json");

	if (outFile.is_open()) {
		outFile << json.dump(-1);
		outFile.close();
	}
	std::cerr << "[ERROR]: Unable to open file for writing\n";
}

Data JsonIO::readValuesFromJson()
{
	Data data;
	std::ifstream inFile("settings.json");
	nlohmann::json json;

	if (!inFile)
	{
		std::cerr << "[ERROR]: File not found\n" << std::endl;
		data.success = false;
		return data;
	}

	try
	{
		inFile >> json;
	} catch (const std::exception &e)
	{
		std::cerr << "[ERROR]: JSON parsing failed: " << e.what() << std::endl;
		data.success = false;
		return data;
	}

	bool readSuccess = true;
	readSuccess &= getValue(json, "token", data.token);
	readSuccess &= getValue(json, "first", data.first);
	readSuccess &= getValue(json, "second", data.second);
	readSuccess &= getValue(json, "third", data.third);

	if (readSuccess)
	{
		data.success = true;
	} else
	{
		std::cerr << "[ERROR]: Failed to read one or more values\n" << std::endl;
		data.success = false;
	}

	return data;
}

nlohmann::json JsonIO::getValuesAsJson(Data data)
{
	nlohmann::json json;

	json["token"] = data.token;
	json["first"] = data.first;
	json["second"] = data.second;
	json["third"] = data.third;

	return json;
}

bool JsonIO::getValue(const nlohmann::json& json, const std::string& key, std::string& value) {
	if (json.contains(key) && json[key].is_string()) {
		value = json[key].get<std::string>();
		return true;
	}
	std::cerr << "[ERROR]: '" << key << "' key is missing or not a string\n";
	return false;
}