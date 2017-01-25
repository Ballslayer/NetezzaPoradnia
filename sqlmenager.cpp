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
    mapaLekarzy.clear();
    while ( query.next()) {
//         qDebug() << "----------";
////        for(int i=0; i<5; i++){
//            qDebug() <<  query.value(0).toString() <<  query.value(1).toString() <<  query.value(2).toString() <<  query.value(3).toString();
////        }
        mapaLekarzy.insert(query.value(0).toInt(), query.value(1).toString());

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
    emit updateComboForLekarz(mapaLekarzy);
}

void SQLMenager::setupModelLek(QStandardItemModel *model)
{
    model->clear();
    QSqlQuery query;
     query.setForwardOnly(true);
    // WYSWIETLANIE
    QString queryStr = "SELECT * FROM LEKI ;";
    // DODAWANIE


    qDebug() << queryStr;
    if (!query.exec(queryStr))
         qDebug() <<  query.lastError();

    QList<QStandardItem*> listaItemow0;
    QList<QStandardItem*> listaItemow1;

    QStandardItem* item0;
    QStandardItem* item1;
    mapaLekow.clear();
    while ( query.next()) {
//         qDebug() << "----------";
////        for(int i=0; i<5; i++){
//            qDebug() <<  query.value(0).toString() <<  query.value(1).toString() <<  query.value(2).toString() <<  query.value(3).toString();
////        }
        mapaLekow.insert(query.value(0).toInt(), query.value(1).toString());

        item0 = new QStandardItem( query.value(0).toString());
        item1 = new QStandardItem( query.value(1).toString());

        listaItemow0.append(item0);
        listaItemow1.append(item1);

    }
    model->appendColumn(listaItemow0);
    model->appendColumn(listaItemow1);

    model->setHeaderData(0, Qt::Horizontal, tr("Kod leku"));
    model->setHeaderData(1, Qt::Horizontal, tr("Nazwa"));
    emit updateComboForLek(mapaLekow);
}

void SQLMenager::setupModelChoroba(QStandardItemModel *model)
{
    model->clear();
    chorobaId = 0;
    QSqlQuery query;
     query.setForwardOnly(true);
    // WYSWIETLANIE
    QString queryStr = "SELECT * FROM CHOROBA ;";
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
    mapaChorob.clear();
    while ( query.next()) {
//         qDebug() << "----------";
////        for(int i=0; i<5; i++){
//            qDebug() <<  query.value(0).toString() <<  query.value(1).toString() <<  query.value(2).toString() <<  query.value(3).toString();
////        }
        int kandydatNaChorobaId = query.value(0).toInt();
        if(kandydatNaChorobaId > chorobaId) chorobaId = kandydatNaChorobaId;
        mapaChorob.insert(kandydatNaChorobaId, query.value(1).toString());
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
    model->setHeaderData(0, Qt::Horizontal, tr("Id choroby"));
    model->setHeaderData(1, Qt::Horizontal, tr("Nazwa choroby"));
    model->setHeaderData(2, Qt::Horizontal, tr("Objawy"));
    model->setHeaderData(3, Qt::Horizontal, tr("Opis"));

    emit updateComboForChoroba(mapaChorob);
    emit updateChorobaId(chorobaId);
}

void SQLMenager::setupModelDawkowanie(QStandardItemModel *model)
{
    model->clear();
    dawkowanieId = 0;
    QSqlQuery query;
     query.setForwardOnly(true);
    // WYSWIETLANIE
    QString queryStr = "SELECT * FROM DAWKOWANIE ;";
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
        int kandydatNa = query.value(0).toInt();
        if(kandydatNa > dawkowanieId) dawkowanieId = kandydatNa;

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
    model->setHeaderData(0, Qt::Horizontal, tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, tr("Lek"));
    model->setHeaderData(2, Qt::Horizontal, tr("Choroba"));
    model->setHeaderData(3, Qt::Horizontal, tr("Dawka"));
    updatedawkowanieId(dawkowanieId);
}

void SQLMenager::setupModelWizyta(QStandardItemModel *model)
{
    model->clear();
    wizytaId = 0;
    QSqlQuery query;
     query.setForwardOnly(true);
    // WYSWIETLANIE
    QString queryStr = "SELECT * FROM WIZYTA ;";
    // DODAWANIE


    qDebug() << queryStr;
    if (!query.exec(queryStr))
         qDebug() <<  query.lastError();

    QList<QStandardItem*> listaItemow0;
    QList<QStandardItem*> listaItemow1;
    QList<QStandardItem*> listaItemow2;
    QList<QStandardItem*> listaItemow3;
    QList<QStandardItem*> listaItemow4;
    QList<QStandardItem*> listaItemow5;
    QList<QStandardItem*> listaItemow6;
    QList<QStandardItem*> listaItemow7;
    QList<QStandardItem*> listaItemow8;
    QStandardItem* item0;
    QStandardItem* item1;
    QStandardItem* item2;
    QStandardItem* item3;
    QStandardItem* item4;
    QStandardItem* item5;
    QStandardItem* item6;
    QStandardItem* item7;
    QStandardItem* item8;

    while ( query.next()) {
//         qDebug() << "----------";
////        for(int i=0; i<5; i++){
//            qDebug() <<  query.value(0).toString() <<  query.value(1).toString() <<  query.value(2).toString() <<  query.value(3).toString();
////        }
        int kandydatNa = query.value(0).toInt();
        if(kandydatNa > wizytaId) wizytaId = kandydatNa;

        item0 = new QStandardItem( query.value(0).toString());
        item1 = new QStandardItem( query.value(1).toString());
        item2 = new QStandardItem( query.value(2).toString());
        item3 = new QStandardItem( query.value(3).toString());
        item4 = new QStandardItem( query.value(4).toString());
        item5 = new QStandardItem( query.value(5).toString());
        item6 = new QStandardItem( query.value(6).toString());
        item7 = new QStandardItem( query.value(7).toString());
        item8 = new QStandardItem( query.value(8).toString());
        listaItemow0.append(item0);
        listaItemow1.append(item1);
        listaItemow2.append(item2);
        listaItemow3.append(item3);
        listaItemow4.append(item4);
        listaItemow5.append(item5);
        listaItemow6.append(item6);
        listaItemow7.append(item7);
        listaItemow8.append(item8);


    }
    model->appendColumn(listaItemow0);
    model->appendColumn(listaItemow1);
    model->appendColumn(listaItemow2);
    model->appendColumn(listaItemow3);
    model->appendColumn(listaItemow4);
    model->appendColumn(listaItemow5);
    model->appendColumn(listaItemow6);
    model->appendColumn(listaItemow7);
    model->appendColumn(listaItemow8);
    model->setHeaderData(0, Qt::Horizontal, tr("Nr wizyty"));
    model->setHeaderData(1, Qt::Horizontal, tr("Data wizyty"));
    model->setHeaderData(2, Qt::Horizontal, tr("Pacjent"));
    model->setHeaderData(3, Qt::Horizontal, tr("Lekarz"));
    model->setHeaderData(4, Qt::Horizontal, tr("Wykryta choroba"));
    model->setHeaderData(5, Qt::Horizontal, tr("Przepisany lek"));
    model->setHeaderData(6, Qt::Horizontal, tr("drugi lek"));
    model->setHeaderData(7, Qt::Horizontal, tr("trzeci lek"));
    model->setHeaderData(8, Qt::Horizontal, tr("czwarty lek"));
    emit updatewizytaId(wizytaId);
}

void SQLMenager::setupModelInterakcja(QStandardItemModel *model)
{
    model->clear();
    interakcjaId = 0;
    QSqlQuery query;
     query.setForwardOnly(true);
    // WYSWIETLANIE
    QString queryStr = "SELECT * FROM INTERAKCJE ;";
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
        int kandydatNa = query.value(0).toInt();
        if(kandydatNa > interakcjaId) interakcjaId = kandydatNa;

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
    model->setHeaderData(0, Qt::Horizontal, tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, tr("Lek nr 1"));
    model->setHeaderData(2, Qt::Horizontal, tr("Lek nr 2"));
    emit updateinterakcjaId(interakcjaId);
}

void SQLMenager::insertIntoLekarze(QString &id, QString &name, QString &tel)
{
    QSqlQuery  query(database);
    QString queryStr("INSERT INTO LEKARZ VALUES ( ");
    queryStr.append(id);
    queryStr.append(" , '");
    queryStr.append(name);
    queryStr.append("' , '");
    queryStr.append(tel);
    queryStr.append(" ') ;");
    qDebug() << "inserting with query: "<< queryStr;

    if (!query.exec(queryStr))
         qDebug() <<  query.lastError();
}

void SQLMenager::insertIntoLek(QString &code, QString &name)
{
    QSqlQuery  query(database);
    QString queryStr("INSERT INTO LEKI VALUES ( ");
    queryStr.append(code);
    queryStr.append(" , '");
    queryStr.append(name);
    queryStr.append(" ') ;");
    qDebug() << "inserting with query: "<< queryStr;

    if (!query.exec(queryStr))
         qDebug() <<  query.lastError();
}

void SQLMenager::insertIntoChoroba(QString &id, QString &nazwa, QString &opis, QString &objawy)
{
    QSqlQuery  query(database);
    QString queryStr("INSERT INTO CHOROBA VALUES ( ");
    queryStr.append(id);
    queryStr.append(" , '");
    queryStr.append(nazwa);
    queryStr.append("' , '");
    queryStr.append(opis);
    queryStr.append("' , '");
    queryStr.append(objawy);
    queryStr.append(" ') ;");
    qDebug() << "inserting with query: "<< queryStr;

    if (!query.exec(queryStr))
         qDebug() <<  query.lastError();
}

void SQLMenager::insertIntoDawkowanie(QString &lek, QString &choroba, QString &dawka)
{
    QSqlQuery  query(database);
    QString queryStr("INSERT INTO DAWKOWANIE VALUES ( ");
    queryStr.append(QString::number(++dawkowanieId));
    queryStr.append(" , '");
    queryStr.append(lek);
    queryStr.append("' , '");
    queryStr.append(choroba);
    queryStr.append("' , '");
    queryStr.append(dawka);
    queryStr.append(" ') ;");
    qDebug() << "inserting with query: "<< queryStr;

    if (!query.exec(queryStr))
         qDebug() <<  query.lastError();
}

void SQLMenager::insertIntoWizyta(QString &id, QString &data, QString &pacjentId, QString &lekarzId, QString &chorobaId, QString &lekiKod, QString &lekiKod2, QString &lekiKod3, QString &lekiKod4)
{

    QSqlQuery  query(database);
    QString queryStr("INSERT INTO WIZYTA VALUES ( ");
    queryStr.append(id);
    queryStr.append(" , '");
    queryStr.append(data);
    queryStr.append("' , '");
    queryStr.append(pacjentId);
    queryStr.append("' , '");
    queryStr.append(lekarzId);
    queryStr.append("' , ");
    if(lekiKod.isEmpty()){
        queryStr.append("0, ");
    } else {
        queryStr.append(" '");
        queryStr.append(chorobaId);
        queryStr.append("' , ");
    }
    if(lekiKod.isEmpty()){
        queryStr.append(" 0, ");
    } else {
    queryStr.append(" '");
    queryStr.append(lekiKod);
    queryStr.append("' , ");
    }
    if(lekiKod2.isEmpty()){
        queryStr.append(" 0, ");
    } else {
        queryStr.append(" '");
        queryStr.append(lekiKod2);
        queryStr.append("' , ");
    }

    if(lekiKod3.isEmpty()){
        queryStr.append(" 0, ");
    } else {
        queryStr.append(" '");
        queryStr.append(lekiKod3);
        queryStr.append("' , ");

    }
    if(lekiKod4.isEmpty()){
        queryStr.append(" 0 )");
    } else {
        queryStr.append(" '");
        queryStr.append(lekiKod4);
        queryStr.append("' ) ");
    }
    qDebug() << "inserting with query: "<< queryStr;

    if (!query.exec(queryStr))
         qDebug() <<  query.lastError();
}

void SQLMenager::insertIntoInterakcja(QString &id, QString &lek1Id, QString &lek2Id)
{
    QSqlQuery  query(database);
    QString queryStr("INSERT INTO INTERAKCJE VALUES ( ");
    queryStr.append(id);
    queryStr.append(" , '");
    queryStr.append(lek1Id);
    queryStr.append("' , '");
    queryStr.append(lek2Id);
    queryStr.append("') ;");
    qDebug() << "inserting with query: "<< queryStr;

    if (!query.exec(queryStr))
         qDebug() <<  query.lastError();
}

void SQLMenager::deleteFromLekarze(QString &id)
{
    QSqlQuery query;
    QString queryStr("DELETE FROM LEKARZ WHERE ID =  ");
    queryStr.append(id);
    qDebug() << queryStr;

    if (!query.exec(queryStr))
         qDebug() <<  query.lastError();
}

void SQLMenager::deleteFromLek(QString &id)
{
    QSqlQuery query;
    QString queryStr("DELETE FROM LEKI WHERE KOD =  ");
    queryStr.append(id);
    qDebug() << queryStr;

    if (!query.exec(queryStr))
         qDebug() <<  query.lastError();
}

void SQLMenager::deleteFromChoroba(QString &id)
{
    QSqlQuery query;
    QString queryStr("DELETE FROM CHOROBA WHERE ID =  ");
    queryStr.append(id);
    qDebug() << queryStr;

    if (!query.exec(queryStr))
         qDebug() <<  query.lastError();
}

void SQLMenager::deleteFromDawkowanie(QString &lekid, QString &chorid)
{
    QSqlQuery query;
    QString queryStr("DELETE FROM DAWKOWANIE WHERE LEK_KOD =  ");
    queryStr.append(lekid);
    queryStr.append(" AND CHOROBA_ID = ");
    queryStr.append(chorid);
    qDebug() << queryStr;

    if (!query.exec(queryStr))
         qDebug() <<  query.lastError();
}

void SQLMenager::deleteFromWizyta(QString &id)
{
    QSqlQuery query;
    QString queryStr("DELETE FROM WIZYTA WHERE ID =  ");
    queryStr.append(id);
    qDebug() << queryStr;

    if (!query.exec(queryStr))
         qDebug() <<  query.lastError();
}

void SQLMenager::deleteFromInterakcja(QString &id)
{
    QSqlQuery query;
    QString queryStr("DELETE FROM INTERAKCJE WHERE ID =  ");
    queryStr.append(id);
    qDebug() << queryStr;

    if (!query.exec(queryStr))
         qDebug() <<  query.lastError();
}

