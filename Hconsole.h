#pragma once
#include <iostream>
#include <Windows.h>
#include <string>

const int HCONSOLE_VERSION = 1;
const int BUILD = 8;
#define HCONSOLE_FULLVER 1.1

/*
	The Hconsole Class which contains everything what Hconsole requires
	Variables, Functions, Enums, Everything!
	TODO: Split
*/
class Hconsole
{
// Private field for all commands functions
private:
	void whoami()
	{
		std::cout << user << std::endl;
		CMD();
	}

	void execCMD() {
		std::string ecmd;
		std::cout << Vol << ":>exec$ ";
		std::cin >> ecmd;

		if (ecmd == "return")
		{
			std::cout << "Returning..." << std::endl;
			CMD();
		}
		else {
			std::cout << "Command '" << ecmd << "' not found" << std::endl;
			execCMD();
		}
	}

	void CMD()
	{
		std::string cmd;
		std::cout << Vol << ":> ";
		std::cin >> cmd;

		if (cmd == "whoami") {
			whoami();
		}
		if (cmd == "echo") {
			std::string ehc;
			std::cin >> ehc;
			std::cout << ehc << std::endl;
			CMD();
		}
		if (cmd == "setusername") {
			std::string newusername;
			std::cout << "New username: ";
			std::cin >> newusername;
			user = newusername;
			std::cout << "Username changed to " << user << std::endl;
			CMD();
		}
		if (cmd == "exec") {
			if (isAdmin == AdminStatus::YES) {
				std::string p;
				std::cout << "[exec] password for " << user << ": ";
				std::cin >> p;
				if (p == pass) {
					execCMD();
				}
				else {
					std::cout << "wrong password" << std::endl;
					CMD();
				}
			}
			else {
				std::cout << "user has not admin permissions" << std::endl;
				CMD();
			}
		}
		if (cmd == "paswd") {
			std::string np;
			std::cout << "set new password for " << user << ": ";
			std::cin >> np;
			pass = np;
			std::cout << "password changed" << std::endl;
			CMD();
		}
		if (cmd == "exit") {
			exit(0);
		}
		if (cmd == "help") {
			std::cout << "HELP			- Shows a list with all avaible commands				" << std::endl;
			std::cout << "WHOAMI		- Shows Who you are										" << std::endl;
			std::cout << "SETUSERNAME	- Changes your Hconsole username						" << std::endl;
			std::cout << "PASWD			- Lets you change your password							" << std::endl;
			std::cout << "EXEC			- [ADMIN] Lets you execute Hconsole Functions			" << std::endl;
			std::cout << "EXIT			- Ends Hconsole											" << std::endl;
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

	void setVars(char vol, std::string username, std::string passwd, bool hasAdmin)
	{
		vol = Vol;
		username = user;
		passwd = pass;
		if (hasAdmin = false) {
			isAdmin = AdminStatus::NO;
		}
		else {
			isAdmin = AdminStatus::YES;
		}
	}

// Private field for all Hconsole variables
private:

	// Used for admin commands
	typedef enum H_adminStatus : short {
		NO = 0,
		LIMMITED = 1,
		YES = 2
	} AdminStatus ;

	char Vol = 'A';
	short isAdmin = AdminStatus::NO;
	std::string user = "USER";
	std::string pass = "1234";
};

