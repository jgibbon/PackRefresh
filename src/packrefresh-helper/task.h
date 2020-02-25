#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QProcess>

#include <QtCore>
#include <sys/types.h> // defines structs
#include <unistd.h>    // defines methods

#include <iostream>

class Task : public QObject
{
    Q_OBJECT
public:
    explicit Task(QObject *parent = nullptr);

signals:
    void finished();

public slots:
    void run();
    void output();
protected:
    QProcess *m_process;
};

#endif // TASK_H
