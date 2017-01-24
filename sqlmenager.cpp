#include "sqlmenager.h"

SQLMenager::SQLMenager(QObject *parent) : QObject(parent)
{

}

bool SQLMenager::initMenager(QSqlDatabase &db)
{
    database = db;
    return true;
}
