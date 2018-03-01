#include "ApplicationCommon.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setStyle(new Qtitan::RibbonStyle());
	a.setApplicationName("Hacate Software");
	ApplicationCommonWindow w;
	w.show();
	return a.exec();
}
