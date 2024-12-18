#ifndef CONSOLE_H
#define CONSOLE_H
#define NOMINMAX
#include <iostream>
#include <string>
#include <Windows.h>
#include "exceptions.h"
namespace out {
	std::string rgbT(const int&, const int&, const int&);
	std::string rgbB(const int&, const int&, const int&);
	std::string move(const int&, const int&);
	extern const char* reset;
	extern const char* endl;
	extern const char* tab;
	int getRow();
	int getCol();
	
}	
static CONSOLE_SCREEN_BUFFER_INFO getConsoleScreenBufferInfo();
#endif // !CONSOLE_H
