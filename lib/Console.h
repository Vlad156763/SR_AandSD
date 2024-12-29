#ifndef CONSOLE_H
#define CONSOLE_H
#define NOMINMAX
#include <iostream>
#include <string>
#include <Windows.h>
#include "exceptions.h"
namespace out {
	std::string rgb(const int& r, const int& g, const int& b, bool for_background = false);
	std::string move(const int& row, const int& col);
	extern const char* reset;
	extern const char* endl;
	extern const char* tab;
	int getRow();
	int getCol();
	int windowXmax();
}
static CONSOLE_SCREEN_BUFFER_INFO getConsoleScreenBufferInfo();
#endif // !CONSOLE_H