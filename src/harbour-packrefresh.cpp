#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

//#include <sailfishapp.h>

#include <QProcess>
#include <QDebug>
#include <QObject>
#include <QFile>
#include <notification.h>

#include <iostream>

int main(int argc, char *argv[])
{
    QProcess *m_process = new QProcess();
    QString terminal("/usr/bin/fingerterm");
    QFile file(terminal);
    if(!file.exists()) {
        QString notFoundSummary("pkcon refresh");
        QString notFoundBody("Trying to refresh in background. Please wait.");
        Notification *notification = new Notification();
        notification->setSummary(notFoundSummary);
        notification->setBody(notFoundBody);
        notification->setPreviewSummary(notFoundSummary);
        notification->setPreviewBody(notFoundBody);
        notification->setExpireTimeout(0);
        notification->publish();
        qDebug() << "no terminal found. " << notFoundBody;

        QObject::connect(m_process, &QProcess::readyReadStandardOutput, m_process, [m_process,notification]() mutable {
            QString stdoutString = QString(m_process->readAllStandardOutput());
            if(stdoutString != "") {
                qDebug() << "stdout" << stdoutString;
            }
            QString stderrString = QString(m_process->readAllStandardError());
            if(stderrString != "") {
                qDebug() << "stderr" << stderrString;
            }
            notification->setBody(stdoutString);
            notification->setPreviewBody(stdoutString);
            notification->publish();
        });
        m_process->start("/usr/share/harbour-packrefresh/helper/packrefreshhelper");
        m_process->waitForFinished(-1);
        return 0;
    }


    m_process->start(terminal + " -e \"/usr/share/harbour-packrefresh/helper/packrefreshhelper;read -p 'Press Enter to exit or close this window.';exit;\"");
    m_process->waitForFinished(-1);
}
