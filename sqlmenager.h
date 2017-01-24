#ifndef SQLMENAGER_H
#define SQLMENAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QStandardItemModel>

class SQLMenager : public QObject
{
    Q_OBJECT
public:
    explicit SQLMenager(QObject *parent = 0);

    bool initMenager(QSqlDatabase &db);

signals:

public slots:
    void setupModelLekarze(QStandardItemModel *model);
    void setupModelLek(QStandardItemModel *model);
    void setupModelChoroba(QStandardItemModel *model);
    void setupModelDawkowanie(QStandardItemModel *model);
    void setupModelWizyta(QStandardItemModel *model);
    void setupModelInterakcja(QStandardItemModel *model);
    void insertIntoLekarze(QString &id, QString &name, QString &tel);
    void insertIntoLek(QString &code, QString &name);
    void insertIntoChoroba(QString &id, QString &nazwa, QString &opis, QString &objawy);
    void insertIntoDawkowanie(QString &lekKod, QString &chorobaId, QString &dawka);
    void insertIntoWizyta(QString &id, QString &data, QString &pacjentId, QString &lekiKod, QString &lekarzId, QString &chorobaId );
    void insertIntoInterakcja(QString &id, QString &lek1Id, QString &lek2Id);
    void deleteFromLekarze(QString &id);
    void deleteFromLek(QString &id);
    void deleteFromChoroba(QString &id);
    void deleteFromDawkowanie(QString &id);
    void deleteFromWizyta(QString &id);
    void deleteFromInterakcja(QString &id);

private:
    QSqlDatabase database;
};

#endif // SQLMENAGER_H
