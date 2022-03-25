#pragma once
#include <iostream>
#include <Windows.h>
#include <string>

class Hconsole
{

// Private field for all commands functions
private:
	void whoami()
	{
		std::cout << user << std::endl;
		CMD();
	}

	void CMD()
	{
		std::string cmd;
		std::cout << Vol << ":> ";
		std::cin >> cmd;

		if (cmd == "whoami") {
			whoami();
		}
		if (cmd == "exit") {
			exit(0);
		}
		if (cmd == "help") {
			std::cout << "HELP		- Shows a list with all avaible commands" << std::endl;
			std::cout << "WHOAMI	- Shows Who you are                     " << std::endl;
			std::cout << "EXIT		- Ends Hconsole                         " << std::endl;
			CMD();
		}
		else {
			std::cout << "Command '" << cmd << "' not found" << std::endl;
			CMD();
		}
	}

// Public field for all Hconsole functions
public:

	void startConsole()
	{
		system("TITLE Hconsole");
		CMD();
	}

	void setVars(char vol, std::string username)
	{
		vol = Vol;
		username = user;
	}

// Private field for all Hconsole variables
private:
	char Vol = 'A';
	std::string user = "USER";
};

