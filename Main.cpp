#include <qapplication.h>
#include <iostream>
#include <string>

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
		cout << "Nothing to work!" << out::endl;
	};
	do {
		std::string debug;
		std::cout << "DEBUG [y/n]: " << std::endl;//\
		std::cin >> debug;//
		debug = "n";
		if (debug == "y" || debug == "Y" || debug == "yes" || debug == "YES" || debug == "Yes") {
			YesDebug();
			break;
		}
		else if (debug == "n" || debug == "N" || debug == "no" || debug == "NO" || debug == "No")  {
			NoDebug();
			break;
		}
		else {
			std::cout << "Don't worry just try again (*_-)" << std::endl;
			continue;
		}
	} while (true);

	return 0;
}