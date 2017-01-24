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


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;

    SQLMenager menager;

    void showError(const QSqlError &err);
    void setModelPacjent();
};

#endif // MAINWINDOW_H
