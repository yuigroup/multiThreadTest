#include "classdataclean.h"

ClassDataClean::ClassDataClean(QObject *parent) : QObject(parent)
{
    qDebug() << QString("%1:%2").arg(__FUNCTION__).arg(__LINE__);
}
