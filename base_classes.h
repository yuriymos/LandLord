#ifndef BASE_CLASSES_H
#define BASE_CLASSES_H

#include <vector>
#include <set>
#include <QString>
#include <algorithm>
#include <numeric>
#include <QTableWidgetItem>
using namespace std;

/*****************************************************************/
// this is a class for each tenant
class tenant
{
private:
    QString FirstName;
    QString LastName;
    int aptNumber;
public:
    tenant(QString Fn, QString Ln, int aNo);
    ~tenant();
    QString FtName() const;
    QString LtName() const;
    int getAptNumber() const;
    // The functions for a set
    friend bool operator < (const tenant&, const tenant&);
    friend bool operator == (const tenant&, const tenant&);
};
/*****************************************************************/
// this is a class for a functional object in order to compare tenants
class compareTenants
{
public:
    bool operator() (tenant*, tenant*) const;
};
/*****************************************************************/
// this is a class to create a list of the tenants
class tenantList
{
private:
    // pointers to tenants
    set<tenant*, compareTenants> setptrTens;
    set<tenant*, compareTenants> :: iterator iter;
public:
    ~tenantList();
    void insertTenant(tenant*);
    int getAptNo(QString,QString);
    int howMany() const; // how many tenants are?
    QTableWidgetItem** display(); // display the list of tenants
};
/*****************************************************************/
// this is a class for a row of a table with rent
class rentRow
{
private:
    int aptNumber;
    float rent[12];
public:
    rentRow(int); // constructor with one argument
    ~rentRow();
    void setRent(int, float); // write rent for each month
    // these are interfaces
    float getSumOfRow(); // this function returns sum of rent for each row
    int getAptNumber() const;
    float getRent(int) const;
    // The functions for a set
    friend bool operator < (const rentRow&, const rentRow&);
    friend bool operator == (const rentRow&, const rentRow&);
};
/*****************************************************************/
// this is a class for a functional object in order to objects rentRow
class compareRows
{
public:
    bool operator() (rentRow*, rentRow*) const;
};
/*****************************************************************/
// this is a class to create a list of the rentRows
class rentRecord
{
private:
    // pointers to tenants
    set<rentRow*, compareRows> setptrRR;
    set<rentRow*, compareRows> :: iterator iter;
public:
    ~rentRecord();
    void insertRent(int,int,float);
    int howMany() const; // how many rows are?
    QTableWidgetItem** display(); // display the list of rows
    float getSumOfRents(); // sum all rental payments
};
/*****************************************************************/
// this is a class for a row of a table with expenses
class expense
{
private:
    int day, month;
    QString payee, category;
    float amount;
public:
    expense()
    {/*it is empty here*/}
    expense(int d, int m, QString p, QString c, float a) :
        day(d), month(m), payee(p), category(c), amount(a)
    {/*it is empty here*/}
    //~expense()
    //{/*it is empty here*/}
    QString getDate() const;
    QString getPayee() const;
    float getAmount() const;
    QString getCategory() const;
    // The functions for a set
    friend bool operator < (const expense&, const expense&);
    friend bool operator == (const expense&, const expense&);
};
/*****************************************************************/
// this is a class for a functional object in order to objects expense
class compareDates
{
public:
    bool operator() (expense*, expense*) const;
};
/*****************************************************************/
// this is a class for a functional object in order to objects expense
class compareCategories
{
public:
    bool operator() (expense*, expense*) const;
};
/*****************************************************************/
// this is a class to create a vector of the expenses
class expenseRecord
{
private:
    // pointers to expenses
    vector<expense*> vectPtrExpenses;
    vector<expense*> :: iterator iter;
public:
    ~expenseRecord();
    void insertExp(expense*);
    int howMany() const; // how many rows are?
    QTableWidgetItem** display(); // display the list of expenses
    float getSumOfExpenses(); // sum all expenses
};
/*****************************************************************/
// this is a class to create an annual Report
class annualReport
{
private:
    rentRecord * ptrRR;
    expenseRecord * ptrER;
    float expenses, rents;
public:
    annualReport(rentRecord*, expenseRecord*);
    QTableWidgetItem** display();
};
#endif // BASE_CLASSES_H
