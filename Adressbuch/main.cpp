#include "adressbuch.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Adressbuch w;
	w.show();
	return a.exec();
}
