#include "Console.h"

std::string out::rgb(const int& r, const int& g, const int& b, bool for_background) {
    return for_background?
        ("\033[48;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) + "m") : 
        ("\033[38;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) + "m");
}	

std::string out::move(const int& row, const int& col) {
	return ("\033["+ std::to_string(row + 1) + ";" + std::to_string(col + 1) + "H");
}

const char* out::reset = "\033[0m";
const char* out::endl = "\n";
const char* out::tab = "    ";
int out::getRow() { return getConsoleScreenBufferInfo().dwCursorPosition.Y; }
int out::getCol() { return getConsoleScreenBufferInfo().dwCursorPosition.X; }
 
int out::windowXmax() {
    return getConsoleScreenBufferInfo().dwMaximumWindowSize.X;
}
int out::windowYmax() {
    return getConsoleScreenBufferInfo().dwMaximumWindowSize.Y;
}

static CONSOLE_SCREEN_BUFFER_INFO getConsoleScreenBufferInfo() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) throw ex("Помилка отримання десктриптора консолі");
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) throw ex("Помилка отримання інформації про буфер екрана консолі");
    return csbi;

}