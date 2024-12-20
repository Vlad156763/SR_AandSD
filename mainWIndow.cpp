#include "mainWIndow.h"
ui::ui(QWidget* parent) :QWidget(parent) {
	this->setWindowTitle("Самостійна робота");
	this->setObjectName("this");
	this->mainLayout = new QGridLayout(this);
	QPushButton* piramidalSort = new QPushButton("Пірамідальне сортування", this); 
	QPushButton* structData = new QPushButton("Структури данних", this);
	QPushButton* spearAlg = new QPushButton("Жадібні алгоритми", this);
	QPushButton* DP = new QPushButton("Динамічне програмуваня", this);
	QPushButton* GraphAlg = new QPushButton("Обхід графів", this);
	QPushButton* GraphAlgSmallWay = new QPushButton("Найкородший шлях графа", this);
	connect(piramidalSort, &QPushButton::released, this, &ui::piramidalSortPressed);
	connect(structData, &QPushButton::released, this, &ui::structDataPressed);
	connect(spearAlg, &QPushButton::released, this, &ui::spearAlgPressed);
	connect(DP, &QPushButton::released, this, &ui::DPPressed);


	GraphAlgSmallWay->setFixedHeight(100);
	piramidalSort->setFixedHeight(100);
	structData->setFixedHeight(100);
	GraphAlg->setFixedHeight(100);
	spearAlg->setFixedHeight(100);
	DP->setFixedHeight(100);
	this->setStyleSheet(
		"#this {"
		"	background-color: rgb(30,30,30);"
		"}"
	);
	QString CSS =
		"QPushButton {"
		"	background-color: rgb(90,90,90);"
		"	border-radius: 5px;"
		"	color: #ffffff;"
		"	font-weight: bold;"
		"	font-size: 16px;"
		"	border: none;"
		"	padding: 10px;"
		"}"
		"QPushButton:focus {"
		"   outline: 0px;"
		"}"
		"QPushButton:hover {"
		"	background-color: rgb(120, 120,120);"
		"}";
	piramidalSort->setStyleSheet(CSS);
	structData->setStyleSheet(CSS);
	spearAlg->setStyleSheet(CSS);
	DP->setStyleSheet(CSS);
	GraphAlgSmallWay->setStyleSheet(CSS);
	GraphAlg->setStyleSheet(CSS);

	this->mainLayout->setSpacing(5);
	this->mainLayout->setContentsMargins(5, 5, 5, 5);
	for (int iterator = 0; iterator < 4; iterator++) {
		this->mainLayout->setRowStretch(iterator, 1);
	}
	this->mainLayout->setColumnStretch(0, 1);
	this->mainLayout->setColumnStretch(1, 1);


	this->mainLayout->addWidget(piramidalSort, 0, 0);
	this->mainLayout->addWidget(structData, 1, 0);
	this->mainLayout->addWidget(spearAlg, 2, 0);
	this->mainLayout->addWidget(DP, 0, 1);
	this->mainLayout->addWidget(GraphAlgSmallWay, 1, 1);
	this->mainLayout->addWidget(GraphAlg, 2, 1);
} 
void ui::piramidalSortPressed() {
	cout << out::rgbT(0, 0, 0) << out::rgbB(23, 103, 99) << " Пірамідальне сортування " << out::reset << out::endl;
}
void ui::structDataPressed() {
	cout << out::rgbT(0, 0, 0) << out::rgbB(23, 103, 99) << " Структури данних " << out::reset << out::endl;
}
void ui::spearAlgPressed() {
	cout << out::rgbT(0,0,0) << out::rgbB(23,103,99) << " Жадібні алгоритми " << out::reset << out::endl;
	QDialog* dialog = new QDialog(this);
	QGridLayout* dialogLayout = new QGridLayout(dialog);
	dialog->setWindowTitle("Жадібні алгоритми");
	QLabel* example = new QLabel(dialog);
	cout << "Варіант No 4." <<
		" Капітан корабля, що зупинився на закинутому острові, вирішив" <<
		" придбати у туземців спеції та заповнити ними всі вільні трюми, щоб" <<
		" заробити якомога більше грошей.Однак всі спеції вмістити у трюми" <<
		" було неможливо, а туземці всі їх продавали за одну й ту саму ціну." <<
		" Знайшовши у одного з матросів записи про те, скільки коштує кожний" <<
		" вид спецій на континенті, приблизно оцінивши наявну кількість" <<
		" кожного виду спецій та знаючи, яку кількість вантажу вмістять вільні" <<
		" трюми, капітан пішов на переговори з туземцями.Визначте" <<
		" оптимальне рішення для капітана." << out::endl;
	QWidget* leftIndividualTask = new QWidget(dialog);
	QWidget* RightHapman = new QWidget(dialog);
	QGridLayout* RightHapmanLayout = new QGridLayout(RightHapman);
	QLabel* titleRight = new QLabel("Хафман", RightHapman);
	QGridLayout* leftIndividualTaskLayout = new QGridLayout(leftIndividualTask);

	QLabel* titleLeft = new QLabel("Завдання", leftIndividualTask);

	QWidget* mainSideleft = new QWidget(leftIndividualTask);
	QGridLayout* mainSideleftLayout = new QGridLayout(mainSideleft);
	titleLeft->setAlignment(Qt::AlignCenter);
	titleRight->setAlignment(Qt::AlignCenter);
	
	titleLeft->setFixedHeight(50);
	titleRight->setFixedHeight(50);
	QWidget* mainRightSide = new QWidget(RightHapman);
	QGridLayout* mainRightSideLayout = new QGridLayout(mainRightSide);
	QLabel* textInLeftSide = new QLabel("Введіть текст, щоб перевірити стискання файлу\n(Ваш текст буде записано у файл, який буде стиснуто)", mainRightSide);
	textInLeftSide->setAlignment(Qt::AlignCenter);
	QTextEdit* RightTextIn = new QTextEdit(mainRightSide);
	QPushButton* squeezeInputText = new QPushButton("Записати та стиснути", mainRightSide);
	QTextEdit* RightTextOut = new QTextEdit(mainRightSide);
	QString cssEditLine =
		"QLineEdit {"
		"   background-color: rgb(70,70,70);"
		"	color: #ffffff;"
		"	border-radius: 5px;"
		"	padding: 5px;"
		"}"
		"QLineEdit:focus {"
		"	outline:none;"
		"}"
		;
	QString cssEditText =
		"QTextEdit {"
		"   background-color: rgb(70,70,70);"
		"	color: #ffffff;"
		"	border-radius: 5px;"
		"	padding: 5px;"
		"}"
		"QTextEdit:focus {"
		"	outline:none;"
		"}"
		"QScrollBar::handle:vertical {"
		"    background: rgb(63,143,139);"
		"    min-height: 10px;"
		"    border-radius: 4px;"
		"    margin: 2px;"
		"}"
		"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {"
		"    height: 0px;"
		"}"
		"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {"
		"    background: none;" //ось це прибирає прозорість блоку, де знаходиться повзунок 
		"}"
		;
	QString csslabel = "QLabel { font-weight: bold;}";
	QString cssTitle =
		"QLabel {"
		"   background-color: rgb(70,70,70);"
		"	font-weight: bold;"
		"	font-size: 16px;"
		"}";
	QString CSS =
		"QWidget {"
		"	background-color: rgb(90,90,90);"
		"	border-radius: 5px;"
		"}";
	QString CssButton =
		"QPushButton {"
		"	background-color: rgb(70,70,70);"
		"	border-radius: 5px;"
		"	color: #ffffff;"
		"	font-weight: bold;"
		"	border: none;"
		"	padding: 10px;"
		"}"
		"QPushButton:focus {"
		"   outline: 0px;"
		"}"
		"QPushButton:hover {"
		"	background-color: rgb(120, 120,120);"
		"}";
	leftIndividualTask->setStyleSheet(CSS);
	RightHapman->setStyleSheet(CSS);
	titleLeft->setStyleSheet(cssTitle);
	titleRight->setStyleSheet(cssTitle);
	RightTextIn->setStyleSheet(cssEditText);
	RightTextOut->setStyleSheet(cssEditText);
	dialogLayout->setColumnStretch(0, 1);
	dialogLayout->setColumnStretch(1, 1);
	dialogLayout->addWidget(leftIndividualTask, 0, 0);
	dialogLayout->addWidget(RightHapman, 0, 1);
	mainSideleftLayout->setColumnStretch(0, 1);
	mainSideleftLayout->setColumnStretch(1, 2);
	squeezeInputText->setStyleSheet(CssButton);
	mainSideleftLayout->setAlignment(Qt::AlignTop);
	leftIndividualTaskLayout->setAlignment(Qt::AlignTop);
	leftIndividualTaskLayout->addWidget(titleLeft, 0, 0, Qt::AlignTop);
	leftIndividualTaskLayout->addWidget(mainSideleft, 1, 0, Qt::AlignTop);
	RightHapmanLayout->setAlignment(Qt::AlignTop);
	RightHapmanLayout->addWidget(mainRightSide, 1,0, Qt::AlignTop);
	mainRightSideLayout->setAlignment(Qt::AlignTop);
	RightHapmanLayout->addWidget(titleRight, 0, 0, Qt::AlignTop);
	mainRightSideLayout->addWidget(textInLeftSide, 0, 0, Qt::AlignTop);
	mainRightSideLayout->addWidget(RightTextIn, 1, 0, 1, 2, Qt::AlignTop);
	mainRightSideLayout->addWidget(squeezeInputText, 2, 0,1, 2, Qt::AlignTop);
	mainRightSideLayout->addWidget(RightTextOut, 3, 0, 1, 2, Qt::AlignTop);

	RightTextOut->setFont(QFont("Courier"));
	connect(squeezeInputText, &QPushButton::released, [RightTextIn, RightTextOut, dialog]() {
		RightTextOut->clear();
		if (RightTextIn->toPlainText().size() == 0) { QMessageBox::critical(dialog, "Помилка", "\nРядок не може бути пустим"); return; }
		fstream file;
		auto ok = [RightTextOut]() mutable {
			RightTextOut->insertPlainText("[ ");
			RightTextOut->setTextColor(QColor(0, 255, 0));
			RightTextOut->insertPlainText("  OK  ");
			RightTextOut->setTextColor(QColor(255, 255, 255));
			RightTextOut->insertPlainText(" ]:  ");
			};
		auto failed = [RightTextOut]() mutable {
			RightTextOut->insertPlainText("[ ");
			RightTextOut->setTextColor(QColor(255, 0, 0));
			RightTextOut->insertPlainText("FAILED");
			RightTextOut->setTextColor(QColor(255, 255, 255));
			RightTextOut->insertPlainText(" ]:  ");
			};
		QString just = "          :  ";
		
		RightTextOut->insertPlainText(just + "Спроба відкрити файл для запису\n");
		file.open("dataHuffMan.txt", std::ios::out | std::ios::trunc);
		if (!file.is_open()) {
			QMessageBox::critical(dialog, "Помилка", "\nНевдалось відкрити файл для запису");
			failed(); RightTextOut->insertPlainText("Невдалось відкрити файл для запису\n");
			return;
		}
		ok(); RightTextOut->insertPlainText("Файл відкрито для запису\n");
		RightTextOut->insertPlainText(just + "Запис данних\n");
		file << RightTextIn->toPlainText().toStdString();
		ok(); RightTextOut->insertPlainText("Данні записані у файл\n");
		file.close();
		RightTextOut->insertPlainText(just + "Спроба відкрити файл для читання\n");
		file.open("dataHuffMan.txt", std::ios::in);
		if (!file.is_open()) {
			QMessageBox::critical(dialog, "Помилка", "\nНевдалось відкрити файл для читання");
			failed(); RightTextOut->insertPlainText("Невдалось відкрити файл для читання\n");

			return;
		}
		ok(); RightTextOut->insertPlainText("Файл відкрито для читання\n");

		//відкриваю цей же файл для стискання
		methodHuffman qa;
		RightTextOut->insertPlainText(just + "Стискання файлу\n");
		qa.Squeeze(file, "data");
		ok(); RightTextOut->insertPlainText("Данні стиснуті (див. у файлах)\n");
		file.close();
		RightTextOut->insertPlainText(just + "Декодування стиснених данних\n");
		string input = qa.Decoder("data");
		ok(); RightTextOut->insertPlainText("Данні успішно декодовані\n");

		RightTextOut->insertPlainText("Вивід декодованих данних:\n");
		RightTextOut->insertPlainText(QString::fromStdString(input));
		RightTextOut->insertPlainText("\n");
		cout << input << out::endl;
	});

	RightTextIn->setFixedHeight(200);
	RightTextOut->setFixedHeight(300);
	textInLeftSide->setStyleSheet(csslabel);

	QLabel* l1 = new QLabel("Вміст трюму (в тоннах)", mainSideleft);
	l1->setAlignment(Qt::AlignCenter );
	QLineEdit* e1 = new QLineEdit(mainSideleft);
	e1->setStyleSheet(cssEditLine);
	l1->setStyleSheet(csslabel);
	mainSideleftLayout->addWidget(l1, 0, 0, Qt::AlignLeft);
	mainSideleftLayout->addWidget(e1, 0, 1);

	QLabel* l2 = new QLabel("Бюджет (в гринях)", mainSideleft);
	l2->setAlignment(Qt::AlignCenter);
	QLineEdit* e2 = new QLineEdit(mainSideleft);
	e2->setStyleSheet(cssEditLine);
	l2->setStyleSheet(csslabel);
	mainSideleftLayout->addWidget(l2, 1, 0, Qt::AlignLeft);
	mainSideleftLayout->addWidget(e2, 1, 1);

	QLabel* l3 = new QLabel("Ціна у туземців (в гринях)", mainSideleft);
	l3->setAlignment(Qt::AlignCenter);
	QLineEdit* e3 = new QLineEdit(mainSideleft);
	e3->setStyleSheet(cssEditLine);
	l3->setStyleSheet(csslabel);
	mainSideleftLayout->addWidget(l3, 2, 0, Qt::AlignLeft);
	mainSideleftLayout->addWidget(e3, 2, 1);

	QLabel* l4 = new QLabel("Продукт та його ціна на континенті\n(Name / Price / KgInNatives)", mainSideleft);
	l4->setAlignment(Qt::AlignCenter);
	l4->setStyleSheet(csslabel);
	mainSideleftLayout->addWidget(l4, 3, 0, 1, 2);

	QTextEdit* te1 = new QTextEdit(mainSideleft);
	te1->setStyleSheet(cssEditText);
	mainSideleftLayout->addWidget(te1, 4, 0, 1, 2);

	QPushButton* b1 = new QPushButton("Результат", mainSideleft);
	mainSideleftLayout->addWidget(b1, 5, 0, 1, 2);
	b1->setStyleSheet(CssButton);

	QTextEdit* te2 = new QTextEdit(mainSideleft);
	te2->setStyleSheet(cssEditText);
	
	mainSideleftLayout->addWidget(te2, 6, 0, 1, 2);
	connect(b1, &QPushButton::released, [e1, e2, e3, te1, te2, dialog]() {
		bool ok = true;
		double t = e1->text().toDouble(&ok);
		double budget = e2->text().toDouble(&ok);
		double priceNatives = e3->text().toDouble(&ok);
		double coppyBudget = budget;
		double priceAllProd = 0;
		
		if (!ok) {
			QMessageBox::warning(dialog, "Попередження", "\nНевірні данні!");
			return;
		}
		QString te1Text = te1->toPlainText();
		QStringList prodPriceKg = te1Text.split(QRegularExpression("[|\\n/\\\\]"));
		te2->clear();
		while (true) {
			double maxPriceInHome = 0;
			int ImaxPrice = 0;
			for (int i = 1; i < prodPriceKg.size(); i += 3) {
				bool okey = true;
				if (prodPriceKg[i].toDouble(&ok) > maxPriceInHome && okey) { 
					maxPriceInHome = prodPriceKg[i].toDouble(); ImaxPrice = i; 
				}
			}
			if (maxPriceInHome <= priceNatives || t == 0 || budget == 0 || prodPriceKg.size() == 0) break;
			double NumkgProduct = 0;
			NumkgProduct = t * 1000;
			NumkgProduct = ((budget / priceNatives) < NumkgProduct) ?( budget / priceNatives ): NumkgProduct;
			NumkgProduct = (NumkgProduct > (prodPriceKg[ImaxPrice + 1].toDouble() * 1000)) ? (prodPriceKg[ImaxPrice + 1].toDouble() * 1000) : NumkgProduct;
			priceAllProd += (NumkgProduct * prodPriceKg[ImaxPrice].toDouble());
			budget -= (NumkgProduct * priceNatives);
			t -= (NumkgProduct / 1000);
			te2->setFont(QFont("Courier"));
			te2->insertPlainText(prodPriceKg[ImaxPrice - 1] + ": ");
			te2->setTextColor(QColor(127, 127, 255));
			te2->insertPlainText(QString::number(NumkgProduct / 1000));
			te2->setTextColor(QColor(255, 255, 255));
			te2->insertPlainText(" т  ");
			te2->setTextColor(QColor(127, 255, 127));
			te2->insertPlainText('+' + QString::number((NumkgProduct * prodPriceKg[ImaxPrice].toDouble())) + "  ");
			te2->setTextColor(QColor(255, 127, 127));
			te2->insertPlainText('-' + QString::number(NumkgProduct * priceNatives) + '\n');
			te2->setTextColor(QColor(255, 255, 255));

			prodPriceKg.removeAt(ImaxPrice - 1);
			prodPriceKg.removeAt(ImaxPrice - 1);
			prodPriceKg.removeAt(ImaxPrice - 1);

		}

		te2->insertPlainText("Об'єм трюму що залишився: "); te2->setTextColor(QColor(127,127,255)); te2->insertPlainText(QString::number(t)); 
		te2->setTextColor(QColor(255, 255, 255)); te2->insertPlainText(" т\n");
		te2->insertPlainText("Бюджет що залишився:      ");	te2->setTextColor(QColor(127,127,255)); te2->insertPlainText(QString::number(budget));
		te2->setTextColor(QColor(255, 255, 255)); te2->insertPlainText(" грн\n");
		te2->insertPlainText("Ціна всієї продукції:     ");	te2->setTextColor(QColor(127,127,255)); te2->insertPlainText(QString::number(priceAllProd)); 
		te2->setTextColor(QColor(255, 255, 255)); te2->insertPlainText(" грн\n");
		te2->insertPlainText("Чистий дохід:             ");	te2->setTextColor(QColor(127,127,255)); te2->insertPlainText(QString::number(budget - coppyBudget + priceAllProd));
		te2->setTextColor(QColor(255, 255, 255)); te2->insertPlainText(" грн\n");
		}
	);
	dialog->setFixedSize(800, 700);
	dialog->exec();
}
void ui::DPPressed() {
	cout << out::rgbT(0, 0, 0) << out::rgbB(23, 103, 99) << " Динамічне програмування " << out::reset << out::endl;

	cout
		<< "Задача 1-Г. \nРядок складається з символів української абетки.У"
		<< " загальному випадку такий рядок представляє собою слово"
		<< " українською мовою.Визначити довжину найдовшого паліндрома"
		<< " (непорожній рядок, який однаково читається як зліва направо, так і"
		<< " справа наліво), який можна утворити шляхом вилучення деяких літер"
		<< " даного рядка, та вивести безпосередньо сам паліндром."; cout << out::endl;
	cout
		<< "Задача 2-Б.\nКомпанія здає автомобіль престижного класу в оренду.В"
		<< " один робочий день було отримано n заявок для оренди.У кожній"
		<< " заявці визначено проміжок часу(si, fi), протягом якого клієнт"
		<< " бажає використовувати автомобіль.При цьому кожній такій заявці та"
		<< " відповідному інтервалу часу відповідає сума коштів pi, яку отримає"
		<< " компанія за оренду.Визначити таке рішення з надання даного"
		<< " автомобіля в оренду за заявками, яке дозволить отримати"
		<< " максимальний прибуток."; cout << out::endl;
	QDialog* dialog = new QDialog(this);
	QGridLayout* dialogLayout = new QGridLayout(dialog);
	dialog->setWindowTitle("Динамічне програмування");
	dialog->setFixedSize(800, 700);
	dialog->setStyleSheet(
		"#QDialog { background-color: rgb(30,30,30); }"
	);
	QWidget* left = new QWidget(dialog); QGridLayout* leftL = new QGridLayout(left);
	QWidget* right= new QWidget(dialog); QGridLayout* rightL = new QGridLayout(right);
	QString cssWidget =
		"QWidget {"
		"	background-color: rgb(90,90,90);"
		"	border-radius: 5px;"
		"}";
	QString csstitlte = 
		"QLabel {"
		"   background-color: rgb(70,70,70);"
		"	font-weight: bold;"
		"	font-size: 16px;"
		"	padding: 10px;"
		"}"
		;
	QString cssEditLine =
		"QLineEdit {"
		"   background-color: rgb(70,70,70);"
		"	color: #ffffff;"
		"	border-radius: 5px;"
		"	padding: 5px;"
		"}"
		"QLineEdit:focus {"
		"	outline:none;"
		"}"
		;
	QString CssButton =
		"QPushButton {"
		"	background-color: rgb(70,70,70);"
		"	border-radius: 5px;"
		"	color: #ffffff;"
		"	font-weight: bold;"
		"	border: none;"
		"	padding: 10px;"
		"}"
		"QPushButton:focus {"
		"   outline: 0px;"
		"}"
		"QPushButton:hover {"
		"	background-color: rgb(120, 120,120);"
		"}";
	QString cssEditText =
		"QTextEdit {"
		"   background-color: rgb(70,70,70);"
		"	color: #ffffff;"
		"	border-radius: 5px;"
		"	padding: 5px;"
		"}"
		"QTextEdit:focus {"
		"	outline:none;"
		"}"
		"QScrollBar::handle:vertical {"
		"    background: rgb(63,143,139);"
		"    min-height: 10px;"
		"    border-radius: 4px;"
		"    margin: 2px;"
		"}"
		"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {"
		"    height: 0px;"
		"}"
		"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {"
		"    background: none;" //ось це прибирає прозорість блоку, де знаходиться повзунок 
		"}"
		;
	QString csslabel = "QLabel { font-weight: bold;}";
	QLabel* t1 = new QLabel("Г",left); 
	QLabel* t2 = new QLabel("Б", right);

	QWidget* leftMain = new QWidget(dialog); QGridLayout* leftLMain = new QGridLayout(leftMain);
	QWidget* rightMain = new QWidget(dialog); QGridLayout* rightLMain = new QGridLayout(rightMain);
	t1->setAlignment(Qt::AlignCenter);
	t2->setAlignment(Qt::AlignCenter);
	t1->setStyleSheet(csstitlte);
	t2->setStyleSheet(csstitlte);
	left->setStyleSheet(cssWidget);
	right->setStyleSheet(cssWidget);
	dialogLayout->setColumnStretch(0, 1);
	dialogLayout->setColumnStretch(1, 1);
	leftL->setAlignment(Qt::AlignTop);
	rightL->setAlignment(Qt::AlignTop);
	leftL->addWidget(t1, 0, 0);
	leftL->addWidget(leftMain, 1, 0);
	rightL->addWidget(t2, 0, 0);
	rightL->addWidget(rightMain, 1, 0);
	dialogLayout->addWidget(left, 0, 0);
	dialogLayout->addWidget(right, 0, 1);

	QLabel* InputLabelInfo = new QLabel("Введіть набір символів \nукраїнської абетки", leftMain);
	QLabel* ResultPalindrom = new QLabel(leftMain);
	QLineEdit* InputText = new QLineEdit(leftMain);
	QPushButton* GetTextButton = new QPushButton("Знайти найдовший паліндром", leftMain);
	QTextEdit* Result = new QTextEdit(leftMain);
	GetTextButton->setStyleSheet(CssButton);
	InputText->setStyleSheet(cssEditLine);
	InputLabelInfo->setStyleSheet(csslabel);
	InputLabelInfo->setAlignment(Qt::AlignCenter);
	leftLMain->addWidget(InputLabelInfo, 0, 0, Qt::AlignTop);
	leftLMain->addWidget(InputText, 1, 0, Qt::AlignTop);
	leftLMain->addWidget(GetTextButton, 2, 0, Qt::AlignTop);
	leftLMain->addWidget(Result, 3, 0, Qt::AlignTop);
	Result->setStyleSheet(cssEditText);
	connect(GetTextButton, &QPushButton::released, [InputText, Result, dialog]() {
		QString text = InputText->text();
		QString resultText;
		QVector<QString> reverseResultFragment;
		if (text.size() == 0) {
			QMessageBox::critical(dialog, "Помилка", "\nРядок не може бути пустим");
			return;
		}
		if (text.size() == 1) {
			Result->clear();
			Result->insertPlainText(text);
		}
		else {
			QVector<QVector<int>> dp(text.size(), QVector<int>(text.size(), 0));
			auto OutTable = [&dp]() {
				for (QVector<int> row : dp) {
					for (int cell : row) {
						cout <<
							(cell == 0? out::rgbT(0, 0, 0) + out::rgbB(255, 255, 255)
								: (cell != 1 && cell != 0)? out::rgbT(0, 255, 0)
								: out::reset) << cell << out::reset << ' ';
					}
					cout << out::endl;
				}
				};
			//заповнення таблиці
			//заповнюю головну діагональ одиницями	
			for (int i = 0; i < text.size(); i++) {
				dp[i][i] = 1;
			}
			cout << out::rgbT(0, 0, 0) << out::rgbB(23, 103, 99) << " Логи для перевірки завдання Г " << out::reset << out::endl;
			cout << "Все що буде виведено далі є таблицею яка потрібна для визначення найдовшого паліндрому"
				<< " шляхом проходження від: [0][n - 1] де n це довжина введених данних, до max([i + 1][j], [i][j-1]) і якщо символ у підрядку"
				<< " [i] == [j] то даний символ записується у вихідний паліндром." << out::endl;
			cout << out::move(out::getRow(), (out::getCol() + ((text.size() + (text.size() - 1)) / 2)));
			cout << 0 << out::endl;
			OutTable(); cout << out::endl;
			for (int i = 0; i + 1 < text.size(); i++) {
				for (int j = 0; j + i + 1 < text.size(); j++) {
					int maxNumber = std::max(dp[j + 1][j + i + 1], dp[j][j + i]);
					if (text[j] == text[j + i + 1]) {
						maxNumber += 2;
					}
					dp[j][j + i + 1] = maxNumber;
				}
				cout << out::move(out::getRow(), (out::getCol() + ((text.size() + (text.size() - 1)) / 2)));
				cout << i + 1 << out::endl;
				OutTable(); cout << out::endl;
			}
			for (int i = 0, j = (text.size() - 1); true; i++, j--) {
				if (i == j) {
					resultText = resultText + text[i];
					for (const auto& ch : reverseResultFragment) {
						resultText = resultText + ch;
					}
					break;
				}
				if (text[i] == text[j]) {
					resultText = resultText + text[i];
					reverseResultFragment.push_front(text[i]);
				}
				else {
					if (dp[i][j - 1] >= dp[i + 1][j]) { i--; }
					else { j++; }
				}
			}
			Result->clear();
			Result->insertPlainText(resultText);
		}
		});
	/*
rightLMain
rightMain
*/
	QLabel* TextInfoRightMain = new QLabel("Ведіть заявки дотримуючись інструкцій", rightMain);
	QLabel* InstructionRightMain = new QLabel("1. Компанія надає одне авто\n2. Компанія надає одне авто на завтрашній день\n3. Вказувати ім'я, час оренди та ціну як у прикладі нижче", rightMain);
	TextInfoRightMain->setAlignment(Qt::AlignCenter);
	QTextEdit* MainInputArearight = new QTextEdit(rightMain); 
	MainInputArearight->setFont(QFont("Courier"));
	MainInputArearight->setPlaceholderText(
		"Ігор миколайович\n"
		"12:00 - 14:30\n"
		"20000\n"
		"\n"
		"Анна Василівна\n"
		"13:00 - 14 : 30\n"
		"50000\n"
	);
	QPushButton* SaveInputData = new QPushButton("Визначити найприбутковіші заявки", rightMain);

	connect(SaveInputData, &QPushButton::released, [MainInputArearight]() {
		cout << MainInputArearight->toPlainText().toStdString();
		});

	TextInfoRightMain->setStyleSheet(csslabel);
	MainInputArearight->setStyleSheet(cssEditText);
	SaveInputData->setStyleSheet(CssButton);
	InstructionRightMain->setStyleSheet(csslabel);

	rightLMain->addWidget(TextInfoRightMain, 0, 0, Qt::AlignTop);
	rightLMain->addWidget(InstructionRightMain, 1, 0, Qt::AlignTop);
	rightLMain->addWidget(MainInputArearight, 2, 0, Qt::AlignTop);
	rightLMain->addWidget(SaveInputData, 3, 0, Qt::AlignTop);


	dialog->exec();
}