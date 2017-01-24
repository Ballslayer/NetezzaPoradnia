#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QSqlQuery>
#include "initdatabase.h"
#include <QList>
#include <QMapIterator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlError err = initDatabase(db);
        if (err.type() != QSqlError::NoError) {
            qDebug() << "initError" << err;
            showError(err);
            return;
        } else {
        menager.initMenager(db);
        }

    chorobaid = 0;

//    QSqlQuery query;
//    query.setForwardOnly(true);
    // WYSWIETLANIE
//    query.prepare("INSERT INTO PACJENT VALUES (1, 'Jakub', 'Michalowski', 'Bydgoszcz', 'mail@mail.com')");
//        query.addBindValue( contactid );
//        query.addBindValue( ct_name );
//        query.addBindValue( extno );
//        query.addBindValue( ct_private );
//        query.addBindValue( ct_favorite );


//        if(!q.exec()) {
//        qDebug() << query.executedQuery();
//        qDebug() <<  query.lastError();
//        } else { qDebug() << " ---- aded client to table PACJENT ----"; }



    connect(&menager,&SQLMenager::updateComboForChoroba,this,&MainWindow::updateComboChoroba);


    modelPacjent = new QStandardItemModel(this);
    modelLekarz = new QStandardItemModel(this);
    modelLek = new QStandardItemModel(this);
    modelChoroba = new QStandardItemModel(this);
    modelDawkowanie = new QStandardItemModel(this);
    modelInterakcja = new QStandardItemModel(this);
    modelWizyta = new QStandardItemModel(this);

//    tModel = new QSqlTableModel(this, db);

//    tModel->setTable("PACJENT");
//    tModel->setEditStrategy(QSqlTableModel::OnFieldChange);
//    tModel->select();
//    qDebug() << tModel->lastError();
//    tModel->fetchMore();
//    ui->tableView_2->setModel(tModel);
    setModelPacjent(); //populate model from a query
    ui->tableView->setModel(modelPacjent);
    menager.setupModelLekarze(modelLekarz);
    menager.setupModelLek(modelLek);
    menager.setupModelChoroba(modelChoroba);
    menager.setupModelDawkowanie(modelDawkowanie);
    menager.setupModelInterakcja(modelInterakcja);
    menager.setupModelWizyta(modelWizyta);

    ui->tableView_2->setModel(modelLekarz);
    ui->tableView_3->setModel(modelLek);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateComboChoroba(QMap<int, QString> &mapaChorob)
{
    ui->comboBoxChorobaDoKasowania->clear();
    ui->comboBox_3chorobaDawkowanie->clear();
    ui->comboBox_wizytaChoroba->clear();

    int index = 0;
    QMapIterator<int, QString> i(mapaChorob);
    while (i.hasNext()) {
        i.next();
        ui->comboBoxChorobaDoKasowania->insertItem(index++,i.value(), QVariant(i.key()));
        ui->comboBox_3chorobaDawkowanie->insertItem(index++,i.value(), QVariant(i.key()));
        ui->comboBox_wizytaChoroba->insertItem(index++,i.value(), QVariant(i.key()));
    }
}

void MainWindow::showError(const QSqlError &err) {
    QMessageBox::critical(this, "Unable to initialize Database",
                          "Error initializing database: " + err.text());
}

void MainWindow::setModelPacjent()
{
    modelPacjent->clear();
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
    modelPacjent->appendColumn(listaItemow0);
    modelPacjent->appendColumn(listaItemow1);
    modelPacjent->appendColumn(listaItemow2);
    modelPacjent->appendColumn(listaItemow3);
    modelPacjent->setHeaderData(0, Qt::Horizontal, tr("Nr Ubezpieczenia"));
    modelPacjent->setHeaderData(1, Qt::Horizontal, tr("Imię i Nazwisko"));
    modelPacjent->setHeaderData(2, Qt::Horizontal, tr("Adres"));
    modelPacjent->setHeaderData(3, Qt::Horizontal, tr("Medium Kontaktu"));
}

void MainWindow::on_pushButton_clicked()
{
    QSqlQuery  query;
    QString queryStr("INSERT INTO PACJENT VALUES ( ");     //10,'Jan','AAAA','bbbb',500400300)"
    queryStr.append(ui->lineEdit->text());
    queryStr.append(" , '");
    queryStr.append(ui->lineEdit_2->text());
    queryStr.append("' , '");
    queryStr.append(ui->lineEdit_3->text());
    queryStr.append("' , '");
    queryStr.append(ui->lineEdit_4->text());
    queryStr.append(" ') ;");
    qDebug() << "inserting with query: "<< queryStr;

    if (!query.exec(queryStr))
         qDebug() <<  query.lastError();
        setModelPacjent();
}

void MainWindow::on_pushButton_2_clicked()
{
    QSqlQuery query;
    QString queryStr("DELETE FROM PACJENT WHERE NR_UBEZPIECZENIA =  ");
    queryStr.append(ui->lineEdit->text());
    qDebug() << queryStr;

    if (!query.exec(queryStr))
         qDebug() <<  query.lastError();
    setModelPacjent();
}

void MainWindow::on_pushButton_dodajLekarza_clicked()
{
    menager.insertIntoLekarze(ui->lineEdit_lekarz_nr->text(),ui->lineEdit_lekarz_imieNazw->text(),ui->lineEdit_telefon->text());
    menager.setupModelLekarze(modelLekarz);
}

void MainWindow::on_pushButton_kasujLekarza_clicked()
{
    menager.deleteFromLekarze(ui->lineEdit_lekarz_nr->text());
    menager.setupModelLekarze(modelLekarz);
}

void MainWindow::on_pushButton_DodajLek_clicked()
{
    menager.insertIntoLek(ui->lineEdit_5kodleku->text(),ui->lineEdit_8nazwalieku->text());
    menager.setupModelLek(modelLek);
}

void MainWindow::on_pushButton_KasujLek_clicked()
{
    menager.deleteFromLek(ui->lineEdit_5kodleku->text());
    menager.setupModelLek(modelLek);
}

void MainWindow::on_pushButton_DodajLek_3_clicked()
{
    //gdy interakcja
}

void MainWindow::on_pushButton_KasujLek_3_clicked()
{
    //gdy interakcja
}

void MainWindow::on_pushButton_DodajChorobe_clicked()
{
    menager.insertIntoChoroba(QString::number(++chorobaid),ui->lineEdit_16nazwaChoroby->text(),ui->plainTextEditOpisChoroby->toPlainText(),ui->plainTextEditObjawyChoroby->toPlainText());
    menager.setupModelChoroba(modelChoroba);
}

void MainWindow::on_pushButton_KasujChorobe_clicked()
{
    menager.deleteFromChoroba(ui->comboBoxChorobaDoKasowania->currentData().toString());
    menager.setupModelChoroba(modelChoroba);
}
