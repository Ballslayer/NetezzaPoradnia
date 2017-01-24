#ifndef INITDATABASE_H
#define INITDATABASE_H

#include <QtSql>

#endif // INITDATABASE_H

/*QSqlError createTables(QSqlQuery &q) {
    if (!q.exec("CREATE TABLE Pacjent (numerUbezpieczenia INTEGER PRIMARY KEY "
                "NOT NULL, imie VARCHAR(10), nazwisko VARCHAR(15), "
                "adres VARCHAR(25), telefon VARCHAR(10))"))
        return q.lastError();
    if (!q.exec("CREATE TABLE Lekarz (lekarzID INTEGER PRIMARY KEY NOT NULL, "
                "imie VARCHAR(10), nazwisko VARCHAR(15), telefon VARCHAR(10))"))
        return q.lastError();
    if (!q.exec("CREATE TABLE Wizyta (wizytaID INTEGER PRIMARY KEY NOT NULL, "
                "numerUbezpieczenia INTEGER NOT NULL, chorobaID INTEGER NOT "
                "NULL, dataWizyty TIMESTAMP, notatkiDlaLekarza VARCHAR(100))"))
        return q.lastError();
    if (!q.exec("CREATE TABLE Diagnoza (wizytaID INTEGER NOT NULL, "
                "chorobaID INTEGER NOT NULL, notatkiDlaPacjenta VARCHAR(100))"))
        return q.lastError();
    if (!q.exec("CREATE TABLE Choroba (chorobaID INTEGER PRIMARY KEY NOT NULL, "
                "lekarstwoID INTEGER NOT NULL, nazwa VARCHAR(20), "
                "opis VARCHAR(70))"))
        return q.lastError();
    if (!q.exec("CREATE TABLE Lekarstwo (lekarstwoID INTEGER PRIMARY KEY "
                "NOT NULL, nazwa VARCHAR(20), opis VARCHAR(70))"))
        return q.lastError();
    if (!q.exec("CREATE TABLE Interakcja (lekarstwoID1 INTEGER NOT NULL, "
                "lekarstwoID2 INTEGER NOT NULL, opis VARCHAR(70))"))
        return q.lastError();
    return QSqlError();
}
*/
/*
QVariant addPacjent(QSqlQuery &q, const int numerUbezpieczenia,
                    const QString &imie, const QString &nazwisko,
                    const QString &adres, const QString &telefon) {
    q.addBindValue(numerUbezpieczenia);
    q.addBindValue(imie);
    q.addBindValue(nazwisko);
    q.addBindValue(adres);
    q.addBindValue(telefon);
    q.exec();
    return numerUbezpieczenia;
}
*/

    //otwarcie
QSqlError initDatabase(QSqlDatabase &db) {
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("NZSQL");
    db.setUserName("admin");
    db.setPassword("password");
    if (!db.open()) {
        qDebug() << "Can't connect with database." << db.lastError();
        return db.lastError();
    } else {
        return QSqlError();
    }


    //stworz tabele. Zakomentowane, bo w przypadku gdy juz sa tworzone to kolejne
    //proby stworzenia zwracaja blad.
    //QSqlError err = createTables(q);
    //if (err.type() != QSqlError::NoError) {
    //    return err;
    //}

    //Wprowadzanie pare wpisow do tabel. Przypisanie QVariantu po to, by
    //zapamietac klucz podstawowy, ktory bedzie potrzebny jako klucz obcy w
    //kolejnych tabelach. Jak tabela nie ma klucza podstawowego to nie przypisuje
    //się do QVariantu.
    /*if (!q.prepare("INSERT INTO Pacjent (numerUbezpieczenia, imie, nazwisko, "
                   "adres, telefon) VALUES (?, ?, ?, ?, ?)"))
        return q.lastError();
        */
    /*
    QVariant swiftID = addPacjent(q, 5437978, "Taylor", "Swift",
                                  "155 Franklin Street", "555-637-236");
    QVariant stopaID = addPacjent(q, 3523637, "Kamil", "Stopa", "Krakowska 14",
                                  "345-387-168");
    QVariant rzeznikID = addPacjent(q, 3662367, "Adam", "Rzeźnik",
                                    "Jana Pawła II 35/14", "758-457-576");
    */
    //zamkniecie
    //QString connectionName = db.connectionName();
    //db.close();
    //db = QSqlDatabase();
    //QSqlDatabase::removeDatabase(connectionName);

}

