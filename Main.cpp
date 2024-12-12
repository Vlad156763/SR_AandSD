#include <qapplication.h>
#include "mainWIndow.h"
int main(int argc, char** argv) {
	QApplication app(argc, argv);
	ui mainWindow;
	mainWindow.show();
	app.exec();
	app.exit();
	return 0;
}