#ifndef SQLMENAGER_H
#define SQLMENAGER_H

#include <QObject>
#include <QSqlDatabase>

class SQLMenager : public QObject
{
    Q_OBJECT
public:
    explicit SQLMenager(QObject *parent = 0);

    bool initMenager(QSqlDatabase &db);

signals:

public slots:

private:
    QSqlDatabase database;
};

#endif // SQLMENAGER_H
