#include <QProcess>

#include <QtCore>
#include <QDebug>
#include "task.h"

int main(int argc, char **argv) {
    std::cout << QString("    _____________").toUtf8().constData() << std::endl;
    std::cout << QString("    |     +     |").toUtf8().constData() << std::endl;
    std::cout << QString("    |   qoOop   |").toUtf8().constData() << std::endl;
    std::cout << QString("    |   (===)   |").toUtf8().constData() << std::endl;
    std::cout << QString("    |           |").toUtf8().constData() << std::endl;
    std::cout << QString("    |   KEEP    |").toUtf8().constData() << std::endl;
    std::cout << QString("    |   CALM    |").toUtf8().constData() << std::endl;
    std::cout << QString("    |    AND    |").toUtf8().constData() << std::endl;
    std::cout << QString("    |   PKCON   |").toUtf8().constData() << std::endl;
    std::cout << QString("    |  REFRESH  |").toUtf8().constData() << std::endl;
    std::cout << QString("    ‾‾‾‾‾‾‾‾‾‾‾‾‾").toUtf8().constData() << std::endl;

    QCoreApplication::setSetuidAllowed(true);
    QCoreApplication a(argc, argv);

    Task *task = new Task(&a);
    QObject::connect(task, SIGNAL(finished()), &a, SLOT(quit()));
    QTimer::singleShot(0, task, SLOT(run()));

    return a.exec();
}
