#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>

#include <QVariant>

#include "AbstractDatabaseTable.h"

class Database : public QObject
{
	Q_OBJECT

public:
	enum SearchType
	{
		Edit, getID
	};
	

	QString hostName ="127.0.0.1";
	QString databaseName ="adressbuch";
	QString userName = "qt";
	QString password = "qt123";
	int port = 3461;


	Database(QObject *parent, QWidget * _MainWidget, QWidget * _controleWidget);
	~Database();
	void connectDb();
	void uiControlsDatabase(bool clear=1);
	void uiControlsDatabase(AbstractDatabaseTable * obj, bool clear);
	void uiViewQuery(QString table, QString filter, QString query, SearchType t = SearchType::Edit, QVariant * output = 0);

	QSqlDatabase getDb() { return this->db; }

public slots:
	void sqlAddTable(AbstractDatabaseTable * obj);
	void sqlAddEntry(AbstractDatabaseTable * obj);
	void sqlSearchEntry(AbstractDatabaseTable * obj);


signals:
	void qslSearchResult(QString, QString, QString);

private:
	QSqlDatabase db;
	QWidget * MainWidget;
	QWidget * controleWidget;
	QSqlTableModel *model;
	QTableView *view;

	AbstractDatabaseTable * currentObj;
	
};

#endif // DATABASE_H