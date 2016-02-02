#include "database.h"
#include "person.h"
#include <QMessageBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

#include <QSqlTableModel>
#include <QTableView>

#include <tuple>

Database::Database(QObject *parent, QWidget * _MainWidget, QWidget * _controleWidget)
	: QObject(parent)
{
	connectDb();
	MainWidget = _MainWidget;
	controleWidget = _controleWidget;
}

Database::~Database()
{

}

void Database::connectDb()
{
	db = QSqlDatabase::addDatabase("QMYSQL");

	db.setHostName(hostName);
	db.setPort(port);
	db.setDatabaseName(databaseName);
	db.setUserName(userName);
	db.setPassword(password);

	if (!db.open()) {
		QMessageBox::critical(0, tr("Cannot open database"),
			tr("Unable to establish a database connection.\n"
				"Click Cancel to exit."), QMessageBox::Cancel);

		qDebug() << db.lastError();
		qDebug() << db.driver();
		qDebug() << db.drivers();
	}
}
void Database::uiControlsDatabase(bool clear)
{
	if (currentObj !=NULL)
	{
	qDebug() << "klciaksd";
		uiControlsDatabase(currentObj, true);
		currentObj->uiCreateInput(MainWidget);
	}
}
void Database::uiControlsDatabase(AbstractDatabaseTable * obj, bool clear)
{
	currentObj = obj;
	//Clear Widget
	if (clear) {
		while (QWidget* w = controleWidget->findChild<QWidget*>())
		{
			delete w->layout();
			delete w;
		}
		delete controleWidget->layout();
	}
	QHBoxLayout *layout = new QHBoxLayout;

	//add table Button
	QSqlQuery query(db);
	auto tableExists = query.exec("SELECT 1 FROM " + obj->getTableName() + " LIMIT 1");
	if (!tableExists)
	{
		QPushButton *addTable_button = new QPushButton(controleWidget);
		addTable_button->setText("Tabelle hinzufuegen");
		connect(addTable_button, &QPushButton::clicked, [=]() { this->sqlAddTable(obj);  });
		layout->addWidget(addTable_button);
	}

	//add Buttons to interakt with Table
	else
	{
		// Eintrag hinzufügen
		QPushButton *addEntry_button = new QPushButton(controleWidget);
		addEntry_button->setText("Eintrag hinzufuegen");
		connect(addEntry_button, &QPushButton::clicked, [=]() { this->sqlAddEntry(obj);  });
		layout->addWidget(addEntry_button);

		// Eintrag suchen
		QPushButton *searchEntry_button = new QPushButton(controleWidget);
		searchEntry_button->setText("Eintrag suchen");
		connect(searchEntry_button, &QPushButton::clicked, [=]() { this->sqlSearchEntry(obj); });
		layout->addWidget(searchEntry_button);
	}

	layout->setAlignment(Qt::AlignLeft);
	controleWidget->setLayout(layout);
}
void Database::uiViewQuery(QString table, QString filter, QString query, SearchType t, QVariant * output)
{
#pragma region contentWidget 
	//delete old Content
	while (QWidget* w = MainWidget->findChild<QWidget*>())
	{
		delete w->layout();
		delete w;
	}
	delete MainWidget->layout();

	//set Layout
	QHBoxLayout *layout = new QHBoxLayout;
	model = new QSqlTableModel(MainWidget, db);
	view = new QTableView(MainWidget);
	layout->addWidget(view);

	//set Content
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	model->setTable(table);
	model->setFilter(filter);
	model->select();

	view->setModel(model);
	view->show();
	MainWidget->setLayout(layout);
#pragma endregion
#pragma region controlesWidget

	//delete old Content
	while (QWidget* w = controleWidget->findChild<QWidget*>())
	{
		delete w->layout();
		delete w;
	}
	delete controleWidget->layout();

	
	if (t == SearchType::Edit)
	{
		//Button apply Changes
		QPushButton *apply_button = new QPushButton(controleWidget);
		apply_button->setText("Bestaetigen");
		connect(apply_button, &QPushButton::clicked, [=]() { model->submitAll(); uiControlsDatabase(); });


		//Button discard Changes
		QPushButton *discardy_button = new QPushButton(controleWidget);
		discardy_button->setText("Abbrechen");
		connect(discardy_button, &QPushButton::clicked, [=]() { model->revertAll(); uiControlsDatabase(); });


		//set Layout
		QHBoxLayout *layoutControle = new QHBoxLayout;
		layoutControle->addWidget(discardy_button);
		layoutControle->addWidget(apply_button);
		controleWidget->setLayout(layoutControle);
	}
	if (t == SearchType::getID)
	{
		QPushButton *select_button = new QPushButton(controleWidget);
		select_button->setText("Auswählen");
		connect(select_button, &QPushButton::clicked, [=]() { model->submitAll(); uiControlsDatabase(); });

		QHBoxLayout *layoutControle = new QHBoxLayout;
		layoutControle->addWidget(select_button);
		controleWidget->setLayout(layoutControle);
		// TODO get ID from Search-Table


		QItemSelectionModel *selmodel = view->selectionModel();
		QModelIndex current = selmodel->currentIndex();
		QModelIndexList selected = selmodel->selectedIndexes();


	}
#pragma endregion
}

void Database::sqlAddEntry(AbstractDatabaseTable * obj)
{
	QSqlQuery query;
	query = obj->sql_getQuery_addEntry(this->db);
	auto success = query.exec();
	if (!success) QMessageBox::critical(0, tr("SQL Query Failed"),
		query.executedQuery(), QMessageBox::Cancel);
}

void Database::sqlSearchEntry(AbstractDatabaseTable * obj)
{
	std::tuple<QString, QString, QString> query;
	query = obj->sql_getQuery_search(this->db);
	uiViewQuery(std::get<0>(query), std::get<1>(query), std::get<2>(query));
}

void Database::sqlAddTable(AbstractDatabaseTable * obj)
{
	QSqlQuery query;
	query = obj->sql_getQuery_addTable(this->db);
	auto success = query.exec();
	if (!success) QMessageBox::critical(0, tr("SQL Query Failed"),
		query.executedQuery(), QMessageBox::Cancel);
}
