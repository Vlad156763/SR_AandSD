#include "Console.h"

std::string out::rgbT(const int& r, const int& g, const int& b) {
	return ("\033[38;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) + "m");
}	
std::string out::rgbB(const int& r, const int& g, const int& b) {
	return ("\033[48;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) + "m");
}
std::string out::move(const int& row, const int& col) {
	return ("\033["+ std::to_string(row + 1) + ";" + std::to_string(col + 1) + "H");
}

const char* out::reset = "\033[0m";
const char* out::endl = "\n";
const char* out::tab = "    ";
int out::getRow() { return getConsoleScreenBufferInfo().dwCursorPosition.Y; }
int out::getCol() { return getConsoleScreenBufferInfo().dwCursorPosition.X; }


static CONSOLE_SCREEN_BUFFER_INFO getConsoleScreenBufferInfo() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) throw ex(1, "Помилка отримання десктриптора консолі");
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) throw ex(2, "Помилка отримання інформації про буфер екрана консолі");
    return csbi;

}
