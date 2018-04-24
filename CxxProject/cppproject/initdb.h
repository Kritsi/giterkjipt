#ifndef INITDB_H
#define INITDB_H
#include <QString>

class initdb
{
public:
    initdb(QString path);
private:
    void initAnimals();
    void initCustomer();
    void initLog();
    void initUsers();
    void initPictures();
    void initCages();
    void initCageRows();
};

#endif // INITDB_H
