#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QSqlQuery>
#include "initdatabase.h"
#include <QList>

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
        }


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






    model = new QStandardItemModel(this);
//    tModel = new QSqlTableModel(this, db);

//    tModel->setTable("PACJENT");
//    tModel->setEditStrategy(QSqlTableModel::OnFieldChange);
//    tModel->select();
//    qDebug() << tModel->lastError();
//    tModel->fetchMore();
//    ui->tableView_2->setModel(tModel);
    setModelPacjent(); //populate model from a query
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::showError(const QSqlError &err) {
    QMessageBox::critical(this, "Unable to initialize Database",
                          "Error initializing database: " + err.text());
}

void MainWindow::setModelPacjent()
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
    QString queryStr("DELETE FROM Przychodnia.pacjent WHERE nr_ubezpieczenia =  ");
    queryStr.append(ui->lineEdit->text());
    qDebug() << queryStr;

    if (!query.exec(queryStr))
         qDebug() <<  query.lastError();
    setModelPacjent();
}
