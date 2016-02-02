#ifndef PERSON_H
#define PERSON_H

/// <includes>
#include "AbstractDatabaseTable.h"
#include <QWidget>
#include <tuple>


/// <summary>
/// Person: SQL Table for storing Information about a person
/// </summary>
/// <seealso cref="QWidget" />
/// <seealso cref="AbstractDatabaseTable" />
class Person :
	public QWidget,
	public virtual  AbstractDatabaseTable
{
	Q_OBJECT

public:
	Person(QString nname = "", QString vname = "", QString strasse = "", QString hnummer = "", QString plz = "", QString ort = "");
	~Person();
	struct name {
		QString nachname;
		QString vorname;
	};

	struct adresse {
		QString strasse;
		QString hausnummer;
		QString plz;
		QString ort;
	};
	struct sqlLength {
		int name;
		int vorname;
		int strasse;
		int hausnummer;
		int plz;
		int ort;
	};

	name name;
	adresse adresse;

	static QString _sql_name_of_table;


	/// <summary>
	/// maximum length of the SQL Strings
	/// </summary>
	static sqlLength _sql_length;


	/// <summary>
	/// Sql_gets the query_search.
	/// </summary>
	/// <param name="db">The database.</param>
	/// <returns>QStrings: name of the table, Filter in SQL w/o WHERE, TODO	</returns>
	//TODO add last parameter (Sort?)
	virtual std::tuple<QString, QString, QString> sql_getQuery_search(QSqlDatabase db);


	/// <summary>
	/// Creates the input GUI for the Class.
	/// </summary>
	/// <param name="MainWidget">The main widget.</param>
	/// <param name="clear">if set to <c>true</c> [clear].</param>
	virtual void uiCreateInput(QWidget *MainWidget, bool clear = true);


	/// <summary>
	/// returns the query to add this table to a database.
	/// </summary>
	/// <param name="db">The database.</param>
	/// <returns>SQL Query</returns>
	virtual QSqlQuery sql_getQuery_addTable(QSqlDatabase db);


	/// <summary>
	/// returns the query to add an Entry to a database.
	/// </summary>
	/// <param name="db">The database.</param>
	/// <returns>SQL Query</returns>
	virtual QSqlQuery sql_getQuery_addEntry(QSqlDatabase db);

	
	/// <summary>
	/// Gets the name of the SQL - table.
	/// </summary>
	/// <returns>name of the SQL table</returns>
	virtual QString getTableName();
	

public slots:
	void setNachname(QString str);
	void setVorname(QString str);
	void setStrasse(QString str);
	void setHausnummer(QString str);
	void setPlz(QString str);
	void setOrt(QString str);

private:




};

#endif // PERSON_H
