#include <QApplication>
#include "landlord.h"
//////////////////////////////////
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    landlord w;
    w.show();
    return a.exec();
}
