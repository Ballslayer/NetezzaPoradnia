#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

    QStandardItemModel *model;
    QSqlTableModel *tModel;


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    void showError(const QSqlError &err);
    void setModelPacjent();
};

#endif // MAINWINDOW_H
