#include <qapplication.h>
#include <iostream>
#include <string>

#include <test.h>
#include "lib/Console.h"
#include "lib/exceptions.h"
#include "mainWIndow.h"

bool SR = false;

int main(int argc, char** argv) {
	auto ProgramIsEnd = []() {
		QString tmp = "Програма завершила роботу. Перезапуск...";
		std::cout << out::move(out::getRow(), (out::windowXmax() - tmp.size())) << out::rgb(0, 255, 0) << tmp.toStdString() << out::reset << out::endl;
		};
	auto ProgramEnd = []() {
		QString tmp = "Програма завершила роботу.";
		std::cout << out::move(out::getRow(), (out::windowXmax() - tmp.size())) << out::rgb(0, 255, 0) << tmp.toStdString() << out::reset << out::endl;
		};
	auto NoDebug = [&](const char* p = "") {
		QApplication app(argc, argv);
		ui mainWindow;
		if (p != "") {   
			mainWindow.setAtributes(QVector<QString>({ p })); 
		}
		QString OpenWindowText = "Відкриваю вікно.";  
		QString OpenWindowSuccess = "Вікно успішно відкрито.";
		QString CloseWindowSuccess = "Вікно успішно закрито.";

		std::cout << out::move(out::getRow(), (out::windowXmax() - OpenWindowText.size())) << out::rgb(255, 255, 255) << OpenWindowText.toStdString() << out::reset << out::endl;
		mainWindow.show();
		std::cout << out::move(out::getRow(), (out::windowXmax() - OpenWindowSuccess.size())) << out::rgb(0, 255, 0) << OpenWindowSuccess.toStdString() << out::reset << out::endl;
		app.exec();
		std::cout << out::move(out::getRow(), (out::windowXmax() - CloseWindowSuccess.size())) << out::rgb(0, 255, 0) << CloseWindowSuccess.toStdString() << out::reset << out::endl;
		app.exit();
		ProgramIsEnd();
	};
	auto YesDebug = [&]() {
		__test t;
		t.show();
		ProgramIsEnd();
	};
	int centerSR = (out::windowXmax() / 2) - (22 / 2);///22 це ширина виводу. 213 це ширина консолі 
	int centerLB = (out::windowXmax() / 2) - (26 / 2);///26 це ширина виводу. 213 це ширина консолі 
	if (SR) {
			std::cout << out::rgb(200, 120, 60) 
			 << out::move(out::getRow(), centerSR) + ",______,  ,______,   \n"
			 << out::move(out::getRow(), centerSR) + "| ,____|  | ,___, \\ \n"
			 << out::move(out::getRow(), centerSR) + "| |       | |___| |  \n"
			 << out::move(out::getRow(), centerSR) + "| |       | ,_____/  \n"
			 << out::move(out::getRow(), centerSR) + "| |____,  | |        \n"
			 << out::move(out::getRow(), centerSR) + "|______|  |_|        \n"
			<< out::endl;
	}
	else {
		std::cout << out::rgb(60, 120, 120)
			 << out::move(out::getRow(), centerLB) + "  ,_______,  ,________,  \n"
			 << out::move(out::getRow(), centerLB) + " / ,____, |  | ,______|  \n"
			 << out::move(out::getRow(), centerLB) + " | |    | |  | |_____,   \n"
			 << out::move(out::getRow(), centerLB) + " | |    | |  | ,____, \\ \n"
			 << out::move(out::getRow(), centerLB) + " | |    | |  | |____| |  \n"
			 << out::move(out::getRow(), centerLB) + " /_/    |_|  |________/  \n"
			 << out::endl;
	}
	std::cout << out::reset;
	do {
		QString debug;
		std::string tmp;
		std::cout << "DEBUG [y/n or end]: ";
		std::getline(std::cin, tmp);
		debug = QString::fromStdString(tmp);
		QStringList parametrs = debug.split(QRegularExpression("\\s+"));
		QRegularExpression rFor_Yes("^[yY](es|ES)?$");
		QRegularExpression rFor_No("^[nN](o|O)?$");
		QRegularExpression RFor_End("^[eE](nd|ND)?$");
		

		if (parametrs.size() == 1 && rFor_Yes.match(parametrs[0]).hasMatch()) {
			YesDebug();
		}
		else if (!parametrs.isEmpty() && rFor_No.match(parametrs[0]).hasMatch()) {
			if (parametrs.size() == 2 && parametrs[1] == "--st") {
				NoDebug(parametrs[1].toStdString().c_str());
			}else if(parametrs.size() == 1)
				NoDebug();
			else {
				std::string tmp = ":(";
				std::cout << out::move(out::getRow() - 1, (out::windowXmax() - tmp.size())) << tmp << out::endl;
			}
		}
		else if (!parametrs.isEmpty() && RFor_End.match(parametrs[0]).hasMatch()) {
			break;
		}
		else if (!parametrs.isEmpty() && (parametrs[0] == "--h" || parametrs[0] == "--help")) {
			std::cout << "mainParametrs secondaryParametrs" << out::endl << out::endl;
			std::cout << "mainParametrs" << out::endl;
			std::cout << "Даний параметр вказує як саме запускається програма (у звичайному режимі, у режимі терміналу, чи завершити програму)" << out::endl << out::endl;
			std::cout << "secondaryParametrs" << out::endl;
			std::cout << "Це набір параметрів які вказують як поводитиме себе програма запускаючись у звичаному режимі." << out::endl;
			std::cout << "1." << out::tab << "--st - цей параметр всатновлює у поля, які довго заповнювати, підготовлений текст. " << out::endl << out::endl;
		}
		else  {
			std::string tmp = ":(";
			std::cout << out::move(out::getRow() - 1, (out::windowXmax() - tmp.size())) << tmp << out::endl;
		}
	} while (true);
	ProgramEnd();
	return 0;
}