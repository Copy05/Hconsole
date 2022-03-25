#include <iostream>
#include <Windows.h>
#include <string>
#include "Hconsole.h"

int main() {
	std::cout << "Hconsole [PUBLIC BETA REALEASE] v0.1\n(c) Copyright Copy05 2021-2022\nAll rights reserved" << std::endl;
	Sleep(1000);
	Hconsole hc;
	hc.startConsole();
}