#pragma once

#include <QSqlDatabase>
#include <QWidget>

/// <summary>
/// Abstract Class for all Classes that will be saved in the SQL
/// </summary>
class AbstractDatabaseTable
{
public:
	AbstractDatabaseTable();
	~AbstractDatabaseTable();

	virtual QSqlQuery sql_getQuery_addTable(QSqlDatabase db);
	virtual QSqlQuery sql_getQuery_addEntry(QSqlDatabase db);
	virtual std::tuple<QString, QString, QString> sql_getQuery_search(QSqlDatabase db);

	virtual QString getTableName();
	virtual void uiCreateInput(QWidget *MainWidget, bool clear = true);
};

