#include "sqlmenager.h"

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QStandardItem>
#include <QStandardItemModel>


SQLMenager::SQLMenager(QObject *parent) : QObject(parent)
{

}

bool SQLMenager::initMenager(QSqlDatabase &db)
{
    database = db;
    return true;
}

void SQLMenager::setupModelLekarze(QStandardItemModel *model)
{
    model->clear();
    QSqlQuery query;
     query.setForwardOnly(true);
    // WYSWIETLANIE
    QString queryStr = "SELECT * FROM LEKARZ ;";
    // DODAWANIE


    qDebug() << queryStr;
    if (!query.exec(queryStr))
         qDebug() <<  query.lastError();

    QList<QStandardItem*> listaItemow0;
    QList<QStandardItem*> listaItemow1;
    QList<QStandardItem*> listaItemow2;
    QStandardItem* item0;
    QStandardItem* item1;
    QStandardItem* item2;

    while ( query.next()) {
//         qDebug() << "----------";
////        for(int i=0; i<5; i++){
//            qDebug() <<  query.value(0).toString() <<  query.value(1).toString() <<  query.value(2).toString() <<  query.value(3).toString();
////        }
        item0 = new QStandardItem( query.value(0).toString());
        item1 = new QStandardItem( query.value(1).toString());
        item2 = new QStandardItem( query.value(2).toString());
        listaItemow0.append(item0);
        listaItemow1.append(item1);
        listaItemow2.append(item2);


    }
    model->appendColumn(listaItemow0);
    model->appendColumn(listaItemow1);
    model->appendColumn(listaItemow2);
    model->setHeaderData(0, Qt::Horizontal, tr("Nr id"));
    model->setHeaderData(1, Qt::Horizontal, tr("Imię i Nazwisko"));
    model->setHeaderData(2, Qt::Horizontal, tr("Kontakt"));
}

void SQLMenager::setupModelLek(QStandardItemModel *model)
{
    model->clear();
    QSqlQuery query;
     query.setForwardOnly(true);
    // WYSWIETLANIE
    QString queryStr = "SELECT * FROM PACJENT ;";
    // DODAWANIE


    qDebug() << queryStr;
    if (!query.exec(queryStr))
         qDebug() <<  query.lastError();

    QList<QStandardItem*> listaItemow0;
    QList<QStandardItem*> listaItemow1;
    QList<QStandardItem*> listaItemow2;
    QList<QStandardItem*> listaItemow3;
    QStandardItem* item0;
    QStandardItem* item1;
    QStandardItem* item2;
    QStandardItem* item3;

    while ( query.next()) {
//         qDebug() << "----------";
////        for(int i=0; i<5; i++){
//            qDebug() <<  query.value(0).toString() <<  query.value(1).toString() <<  query.value(2).toString() <<  query.value(3).toString();
////        }
        item0 = new QStandardItem( query.value(0).toString());
        item1 = new QStandardItem( query.value(1).toString());
        item2 = new QStandardItem( query.value(2).toString());
        item3 = new QStandardItem( query.value(3).toString());
        listaItemow0.append(item0);
        listaItemow1.append(item1);
        listaItemow2.append(item2);
        listaItemow3.append(item3);


    }
    model->appendColumn(listaItemow0);
    model->appendColumn(listaItemow1);
    model->appendColumn(listaItemow2);
    model->appendColumn(listaItemow3);
    model->setHeaderData(0, Qt::Horizontal, tr("Nr Ubezpieczenia"));
    model->setHeaderData(1, Qt::Horizontal, tr("Imię i Nazwisko"));
    model->setHeaderData(2, Qt::Horizontal, tr("Adres"));
    model->setHeaderData(3, Qt::Horizontal, tr("Medium Kontaktu"));
}

void SQLMenager::setupModelChoroba(QStandardItemModel *model)
{

}

void SQLMenager::setupModelDawkowanie(QStandardItemModel *model)
{

}

void SQLMenager::setupModelWizyta(QStandardItemModel *model)
{

}

void SQLMenager::setupModelInterakcja(QStandardItemModel *model)
{

}

void SQLMenager::insertIntoLekarze(QString &id, QString &name, QString &tel)
{

}

void SQLMenager::insertIntoLek(QString &code, QString &name)
{

}

void SQLMenager::insertIntoChoroba(QString &id, QString &nazwa, QString &opis, QString &objawy)
{

}

void SQLMenager::insertIntoDawkowanie(QString &lekKod, QString &chorobaId, QString &dawka)
{

}

void SQLMenager::insertIntoWizyta(QString &id, QString &data, QString &pacjentId, QString &lekiKod, QString &lekarzId, QString &chorobaId)
{

}

void SQLMenager::insertIntoInterakcja(QString &id, QString &lek1Id, QString &lek2Id)
{

}

void SQLMenager::deleteFromLekarze(QString &id)
{

}

void SQLMenager::deleteFromLek(QString &id)
{

}

void SQLMenager::deleteFromChoroba(QString &id)
{

}

void SQLMenager::deleteFromDawkowanie(QString &id)
{

}

void SQLMenager::deleteFromWizyta(QString &id)
{

}

void SQLMenager::deleteFromInterakcja(QString &id)
{

}

