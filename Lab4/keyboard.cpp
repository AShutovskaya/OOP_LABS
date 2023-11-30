#include "keyboard.hpp"

namespace AS
{
		Keyboard::Keyboard() = default;
		Keyboard::~Keyboard()
		{

		}

		void Keyboard::addCommand(const std::string& key, const std::string& cmd)
		{
			_commands.insert({ key, cmd });
			_keys += key;
		}

		void Keyboard::pressKey(const std::string& key)
		{
			std::cout << _commands[key] << std::endl;
		}

		void Keyboard::WorkFlow(const std::string& strKey)
		{
			setlocale(LC_ALL, "Rus");
			parse(strKey);

			for (const auto& i : keys_vector)
			{
				std::cout << _commands[i] << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds{500});
			}

			std::cout << "WORKFLOW ÎÊÎÍ×ÅÍ" << std::endl;
			std::cout << "-----" << std::endl;
		}

		void Keyboard::Undo()
		{
			std::cout << "ÎÒÌÅÍÀ ÏÎÑËÅÄÍÅÃÎ ÄÅÉÑÒÂÈß" << std::endl;
			setlocale(LC_ALL, "Rus");
			keys_vector.erase(keys_vector.end() - 1);

			for (const auto& i : keys_vector)
			{
				std::cout << _commands[i] << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds{500});
			}

			std::cout << "-----" << std::endl;
		}

		void Keyboard::parse(std::string keys)
		{
			std::stringstream keyssStringstream(keys);
			std::string str;

			for (int i = 0; i < keys.length(); i++)
			{

				if (getline(keyssStringstream, str, ' '))
				{
					keys_vector.push_back(str);
				}
			}

		}

}