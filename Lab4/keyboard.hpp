#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <thread>
#include <chrono>

namespace AS
{
	class Keyboard
	{
	public:
		Keyboard();
		~Keyboard();

		void addCommand(const std::string& key, const std::string& cmd);

		void pressKey(const std::string& key);

		void WorkFlow(const std::string& strKey);

		void Undo();

	private:

		std::string _keys, _pressedKey;
		std::vector<std::string> keys_vector;
		std::unordered_map<std::string, std::string> _commands;

		void parse(std::string keys);

	};
}