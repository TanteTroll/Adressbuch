#include "AbstractDatabaseTable.h"
#include <QSqlQuery>
#include <tuple>

AbstractDatabaseTable::AbstractDatabaseTable()
{
}

AbstractDatabaseTable::~AbstractDatabaseTable()
{
}

QSqlQuery AbstractDatabaseTable::sql_getQuery_addTable(QSqlDatabase db)
{
	qDebug("you should not see this. -AbstractClassTable");
	return QSqlQuery();
}

QSqlQuery AbstractDatabaseTable::sql_getQuery_addEntry(QSqlDatabase db)
{
	qDebug("you should not see this. -AbstractClassTable");
	return QSqlQuery();
}

std::tuple<QString, QString, QString> AbstractDatabaseTable::sql_getQuery_search(QSqlDatabase db)
{
	std::tuple<QString, QString, QString> re("", "", "");
	qDebug("you should not see this. -AbstractClassTable");
	return  re;
}

QString AbstractDatabaseTable::getTableName()
{
	return QString();
}

void AbstractDatabaseTable::uiCreateInput(QWidget * MainWidget, bool clear)
{
}
