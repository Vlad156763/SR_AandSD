#include <qapplication.h>
#include <iostream>
#include <string>

#include <test.h>
#include "lib/Console.h"
#include "lib/exceptions.h"
#include "mainWIndow.h"
int main(int argc, char** argv) {
	auto NoDebug = [&]() {
		QApplication app(argc, argv);
		ui mainWindow;
		mainWindow.show();
		app.exec();
		app.exit();
	};
	auto YesDebug = [&]() {
		__test t;
		t.show();
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