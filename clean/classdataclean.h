#ifndef CLASSDATACLEAN_H
#define CLASSDATACLEAN_H

#include <QObject>
#include <QDebug>

class ClassDataClean : public QObject
{
    Q_OBJECT
public:
    explicit ClassDataClean(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CLASSDATACLEAN_H
