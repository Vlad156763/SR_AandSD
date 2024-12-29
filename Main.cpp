#include <qapplication.h>
#include <iostream>
#include <string>

#include <test.h>
#include "lib/Console.h"
#include "lib/exceptions.h"
#include "mainWIndow.h"



int main(int argc, char** argv) {
	auto ProgramIsEnd = []() {
		std::string tmp = "Програма завершила роботу. Перезапуск...";
		int sizeTmp = 40;
		std::cout << out::move(out::getRow(), (out::windowXmax() - sizeTmp)) << out::rgb(0, 255, 0) << tmp << out::reset << out::endl;
		};
	auto NoDebug = [&]() {
		QApplication app(argc, argv);
		ui mainWindow;
		mainWindow.show();
		app.exec();
		app.exit();
		ProgramIsEnd();
	};
	auto YesDebug = [&]() {
		__test t;
		t.show();
		ProgramIsEnd();
	};
	do {
		std::string debug;
		std::cout << "DEBUG [y/n or end]: ";//
		std::cin >> debug;//
		if (debug == "y" || debug == "Y" || debug == "yes" || debug == "YES" || debug == "Yes") {
			YesDebug();

		}
		else if (debug == "n" || debug == "N" || debug == "no" || debug == "NO" || debug == "No")  {
			NoDebug();
		}
		else if (debug == "end" || debug == "END" || debug == "End") {
			break;
		}
		else {
			std::cout << "Don't worry just try again (*_-)" << std::endl;
			continue;
		}
	} while (true);

	return 0;
}