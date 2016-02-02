#include "adressbuch.h"

#include "person.h"
#include "AbstractDatabaseTable.h"

#include <QSqlQuery>


#include <QDebug>
#include <QTableWidget>

Adressbuch::Adressbuch(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	db = new Database(this, ui.contentWidget, ui.controlWidget);
	//connect(db, &Database::qslSearchResult, this, &Adressbuch::printSearchQuery);

}

Adressbuch::~Adressbuch()
{

}

void Adressbuch::printSearchQuery(QString table, QString filter, QString query)
{
	

}

void Adressbuch::on_adressButton_clicked()
{
	Person *newEntry = new Person();
	
	db->uiControlsDatabase(newEntry, true);
	newEntry->uiCreateInput(ui.contentWidget);
}