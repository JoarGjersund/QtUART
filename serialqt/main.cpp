#include "serialqt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	serialqt w;
	w.show();
	return a.exec();
}
