#include "person.h"

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>	
#include <QPushButton>
#include <qlineedit.h>
#include <qlabel.h>
#include <QGridLayout>
#include <QSpacerItem>
#include <QSqlError>
#include <QSqlRecord>

#include <tuple>


/// <summary>
/// The _sql_name_of_table{CC2D43FA-BBC4-448A-9D0B-7B57ADF2655C}
/// </summary>
QString Person::_sql_name_of_table("adresse");


struct Person::sqlLength Person::_sql_length {  30, 50, 20, 10, 5, 100 };
//struct sqlLength {
//	int name;
//	int vorname;
//	int strasse;
//	int hausnummer;
//	int plz;
//	int ort;
//};

Person::Person(QString nname, QString vname, QString strasse, QString hnummer, QString plz, QString ort)
	: QWidget()
{
	name.nachname = nname;
	name.vorname = vname;
	adresse.strasse = strasse;
	adresse.hausnummer = hnummer;
	adresse.plz = plz;
	adresse.ort = ort;
}

Person::~Person()
{
	
}

QSqlQuery Person::sql_getQuery_addTable(QSqlDatabase db)
{
	QSqlQuery query(db);

	query.prepare("CREATE TABLE " + _sql_name_of_table + " (ID int NOT NULL AUTO_INCREMENT,  "

		"nachname varchar( :lnachname ),"
		"vorname varchar( :lvorname ),"

		"strasse varchar( :lstrasse ),"
		"hausnummer varchar( :lhausnummer ),"
		"plz varchar( :lplz ),"
		"ort varchar( :lort ),"
		"PRIMARY KEY(ID))");

	query.bindValue(":lnachname", _sql_length.name);
	query.bindValue(":lvorname", _sql_length.vorname);

	query.bindValue(":lstrasse", _sql_length.strasse);
	query.bindValue(":lhausnummer", _sql_length.hausnummer);
	query.bindValue(":lplz", _sql_length.plz);
	query.bindValue(":lort", _sql_length.ort);

	return query;
}

QSqlQuery Person::sql_getQuery_addEntry(QSqlDatabase db)
{
	QSqlQuery query;

	query.prepare("INSERT INTO " + _sql_name_of_table + " (nachname, vorname, strasse, hausnummer, plz, ort) "
		"VALUES (:nachname, :vorname, :strasse, :hausnummer, :plz, :ort)");
	query.bindValue(":nachname", name.nachname, QSql::Out);
	query.bindValue(":vorname", name.vorname, QSql::Out);

	query.bindValue(":strasse", adresse.strasse, QSql::Out);
	query.bindValue(":hausnummer", adresse.hausnummer, QSql::InOut);
	query.bindValue(":plz", adresse.plz, QSql::Out);
	query.bindValue(":ort", adresse.ort, QSql::Out);
	
	return query;
}

std::tuple<QString, QString, QString> Person::sql_getQuery_search(QSqlDatabase db)
{
	std::tuple<QString, QString, QString> query
		(_sql_name_of_table,
			"nachname LIKE '" + name.nachname + "%' AND "
			"vorname LIKE '" + name.vorname + "%' AND "
			"strasse LIKE '" + adresse.strasse + "%' AND "
			"hausnummer LIKE '" + adresse.hausnummer + "%' AND "
			"plz LIKE '" + adresse.plz + "%' AND "
			"ort LIKE '" + adresse.ort + "%'", "" );

	return query;
}

void Person::uiCreateInput(QWidget *MainWidget, bool clear)
{
	if (clear) {
		while (QWidget* w = MainWidget->findChild<QWidget*>())
		{
			delete w->layout();
			delete w;
		}
		delete MainWidget->layout();
	}

	//create Buttons
	QLabel *surname_label = new QLabel(MainWidget);
	QLineEdit  *surname_line = new QLineEdit(MainWidget);
	surname_label->setText("Vorname");
	surname_line->setText(name.vorname);
	QLabel *name_label = new QLabel(MainWidget);
	QLineEdit  *name_line = new QLineEdit(MainWidget);
	name_label->setText("Nachname");
	name_line->setText(name.nachname);
	QLabel *street_label = new QLabel(MainWidget);
	QLineEdit  *street_line = new QLineEdit(MainWidget);
	street_label->setText("Strasse");
	street_line->setText(adresse.strasse);
	QLabel *streetnr_label = new QLabel(MainWidget);
	QLineEdit  *streetnr_line = new QLineEdit(MainWidget);
	streetnr_label->setText("Nummer");
	streetnr_line->setText(adresse.hausnummer);
	QLabel *plz_label = new QLabel(MainWidget);
	QLineEdit  *plz_line = new QLineEdit(MainWidget);
	plz_label->setText("PLZ");
	plz_line->setText(adresse.plz);
	QLabel *ort_label = new QLabel(MainWidget);
	QLineEdit  *ort_line = new QLineEdit(MainWidget);
	ort_label->setText("Ort");
	ort_line->setText(adresse.ort);

	//set Layouts
	QVBoxLayout *layout = new QVBoxLayout;
	QHBoxLayout *layout_name = new QHBoxLayout;
	QHBoxLayout *layout_adre = new QHBoxLayout;
	QHBoxLayout *layout_comm = new QHBoxLayout;
	layout_name->addWidget(surname_label);
	layout_name->addWidget(surname_line);
	layout_name->addWidget(name_label);
	layout_name->addWidget(name_line);

	layout_adre->addWidget(street_label);
	layout_adre->addWidget(street_line);
	layout_adre->addWidget(streetnr_label);
	layout_adre->addWidget(streetnr_line);
	layout_adre->addWidget(plz_label);
	layout_adre->addWidget(plz_line);
	layout_adre->addWidget(ort_label);
	layout_adre->addWidget(ort_line);

	layout->addLayout(layout_name);
	layout->addLayout(layout_adre);

	layout->setAlignment(Qt::AlignTop);
	layout_name->setAlignment(Qt::AlignLeft);
	layout_adre->setAlignment(Qt::AlignRight);

	//set Input type

	//connect
	connect(surname_line, &QLineEdit::textChanged, this, &Person::setVorname );
	connect(name_line, &QLineEdit::textChanged, this, &Person::setNachname);
	connect(street_line, &QLineEdit::textChanged, this, &Person::setStrasse);
	connect(plz_line, &QLineEdit::textChanged, this, &Person::setPlz);
	connect(ort_line, &QLineEdit::textChanged, this, &Person::setOrt);
	connect(streetnr_line, &QLineEdit::textChanged, this, &Person::setHausnummer);

	MainWidget->setLayout(layout);
}

QString Person::getTableName()
{
	return _sql_name_of_table;
}

void Person::setNachname(QString str)
{
	name.nachname = str;
}

void Person::setVorname(QString str)
{
	name.vorname = str;
}

void Person::setStrasse(QString str)
{
	adresse.strasse = str;
}

void Person::setHausnummer(QString str)
{
	adresse.hausnummer = str;
}

void Person::setPlz(QString str)
{
	adresse.plz = str;
}

void Person::setOrt(QString str)
{
	adresse.ort = str;
}


