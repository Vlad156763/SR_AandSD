#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <qwidget.h>
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
using std::cout;
using std::endl;
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

};
#endif // !MAINWINDOW_H