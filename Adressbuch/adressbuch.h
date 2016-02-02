#ifndef ADRESSBUCH_H
#define ADRESSBUCH_H

#include <QtWidgets/QMainWindow>
#include "ui_adressbuch.h"
#include "database.h"
#include <QSqlQuery>


class Adressbuch : public QMainWindow
{
	Q_OBJECT

public:
	Adressbuch(QWidget *parent = 0);
	~Adressbuch();

private slots:
	void on_adressButton_clicked();
	void printSearchQuery(QString table, QString filter, QString query);
	// TODO delete [printSearchQuery]

private:
	Ui::AdressbuchClass ui;

	Database  * db;

};

#endif // ADRESSBUCH_H
