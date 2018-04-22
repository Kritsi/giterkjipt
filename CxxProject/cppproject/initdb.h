#ifndef INITDB_H
#define INITDB_H
#include <QString>

class initdb
{
public:
    initdb();
    void initDatabase(QString path);
private:
    void initAnimals();
    void initCages();
    void initCustomer();
    void initLog();
    void initUsers();
    void initCageRows();
};

#endif // INITDB_H
