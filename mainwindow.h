#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "sqlmenager.h"

#include <QMainWindow>
#include <QtWidgets>
#include <QSqlError>
#include <QSqlRelationalTableModel>
#include <QtSql>
#include <QDebug>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QSqlTableModel>
#include <QMap>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QStandardItemModel *modelPacjent;
    QStandardItemModel *modelLekarz;
    QStandardItemModel *modelLek;
    QStandardItemModel *modelChoroba;
    QStandardItemModel *modelDawkowanie;
    QStandardItemModel *modelWizyta;
    QStandardItemModel *modelInterakcja;
    QSqlTableModel *tModel;

public slots:
    void updateComboChoroba(QMap<int,QString> &);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_dodajLekarza_clicked();

    void on_pushButton_kasujLekarza_clicked();

    void on_pushButton_DodajLek_clicked();

    void on_pushButton_KasujLek_clicked();

    void on_pushButton_DodajLek_3_clicked();

    void on_pushButton_KasujLek_3_clicked();

    void on_pushButton_DodajChorobe_clicked();

    void on_pushButton_KasujChorobe_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;

    int chorobaid;
    SQLMenager menager;

    void showError(const QSqlError &err);
    void setModelPacjent();
};

#endif // MAINWINDOW_H
