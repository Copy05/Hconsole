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

// Public field for all Hconsole functions
public:

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
		else {
			std::cout << "Command '" << cmd << "' not found" << std::endl;
			CMD();
		}
	}

// Private field for all Hconsole variables
private:
	char Vol = 'A';
	std::string user = "USER";
};

