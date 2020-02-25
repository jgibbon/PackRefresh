#include "task.h"
#include <QDebug>

Task::Task(QObject *parent) : QObject(parent),
    m_process(new QProcess(this))
{
}

void Task::run() {
    if (setuid(0) != 0) {
        perror("Setuid failed, no suid-bit set?");
        emit finished();
        return;
    }
    setuid(0);
    connect (m_process, SIGNAL(readyReadStandardOutput()), this, SLOT(output()));  // connect process signals with your code
    connect (m_process, SIGNAL(readyReadStandardError()), this, SLOT(output()));  // same here
    m_process->start("/usr/bin/pkcon refresh");
    m_process->waitForFinished(-1);
    emit finished();
}

void Task::output() {
    QString stdoutString = QString(m_process->readAllStandardOutput());
    if(stdoutString != "") {
        std::cout << stdoutString.toUtf8().constData() << std::flush;
    }
    QString stderrString = QString(m_process->readAllStandardError());
    if(stderrString != "") {
        std::cout << "ERROR " << stderrString.toUtf8().constData() << std::flush;
    }
}
