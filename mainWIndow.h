#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <qwidget.h>
#include <qapplication.h>
#include <qgridlayout.h>
#include <qpushbutton.h>
#include <qdialog.h>
#include <iostream>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qmessagebox.h>
#include <qstring.h>	
#include <qstringlist.h>
#include <qregularexpression.h>
#include <qfont.h>
#include <qvector.h>
#include <qdebug.h>

#include "lib/algorithms.h"
#include "lib/Console.h"
#include "lib/exceptions.h"

#include <fstream>
#include <iomanip>

using std::cout;
#define cqdout qDebug()

class ui :public QWidget {
private:
	QGridLayout* mainLayout = nullptr;
public:
	ui(QWidget* = nullptr);
public slots:
	void piramidalSortPressed();
	void structDataPressed();
	void spearAlgPressed();
	void DPPressed();
	void SmallWayInGraphPressed();

};
#endif // !MAINWINDOW_H
