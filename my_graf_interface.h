#ifndef MY_GRAFIC_H_
#define MY_GRAFIC_H_

#include "landlord.h"
/*****************************************************************/
// this class allows to validate data
class NameValidator : public QValidator
{
public:
    NameValidator(QObject * parent) : QValidator(parent)
    {

    }
    virtual State validate(QString& str, int& pos) const
    {
        QRegExp rxp = QRegExp("[0-9]");
        pos = pos;
        if(str.contains(rxp) || str.contains(" "))
        {
            return Invalid;
        }
        return Acceptable;
    }
};
/*****************************************************************/
// this class allows to create a Graphical Dialog for inputting tenant
class InputTenant : public QDialog
{
private:
    QLineEdit * ptrFirstName;
    QLineEdit * ptrLastName;
    QComboBox * ptrAptNumber;
public:
    InputTenant(QWidget * parent = 0); // parent equal to zero in the header!
    QString roomNumber() const; // to get a room number
    QString firstName() const; // to get a first name of the tenant
    QString lastName() const; // to get a last name of the tenant
};
/*****************************************************************/
// this class allows to create a Graphical Dialog for inputting rent
class InputRent : public QDialog
{
private:
    QComboBox * ptrAptNumber; // to choose a number of an apartment
    QComboBox * ptrMonth;
    QLineEdit * ptrMoney; // to input amount of rent for a tenant

public:
    InputRent(QWidget * parent = 0); // parent equal to zero in the header!
    QString roomNumber() const; // to get a room number
    int MonthOfYear() const; // to get a Months of a year
    QString Money() const; // to get a rent
};
/*****************************************************************/
// this class allows to create a Graphical Dialog for inputting expenses
class InputExpenses : public QDialog
{
private:
    QComboBox * ptrDayOfMonth;
    QComboBox * ptrMonth;
    QLineEdit * ptrNameOrCompany; // to input a last name of a receiver
    QLineEdit * ptrMoney; // to input amount of Expenses
    QComboBox * ptrCategory; // to input a category of the Expenses

public:
    InputExpenses(QWidget * parent = 0); // parent equal to zero in the header!
    int DayOfMonth() const; // to get a day
    int anyMonth() const; // to get a Month
    QString NameOrCompany() const; // to get a person's name or a company
    QString anyCategory() const; // to get a Category
    QString Money() const; // to get a Expense
};
/*****************************************************************/
// this class allows to create a OutputTenantList
class OutputTenantList : public QDialog
{
private:
    QTableWidget * ptrTable;
public:
    OutputTenantList(QWidget * parent = 0, tenantList * ptrTL = 0); // parent equal to zero in the header!
};
/*****************************************************************/
// this class allows to create a OutputRentList
class OutputRentList : public QDialog
{
private:
    QTableWidget * ptrTable;
public:
    OutputRentList(QWidget * parent = 0, rentRecord * ptrRR = 0); // parent equal to zero in the header!
};
/*****************************************************************/
// this class allows to create a OutputExpensesList
class OutputExpensesList : public QDialog
{
private:
    QTableWidget * ptrTable;
public:
    OutputExpensesList(QWidget * parent = 0, expenseRecord * ptrExp = 0); // parent equal to zero in the header!
};
/*****************************************************************/
// this class allows to create an interface of the annual report
class OutputAnnualReport : public QDialog
{
private:
    QTableWidget * ptrTable;
public:
    OutputAnnualReport(QWidget * parent = 0, annualReport * ptrAnRep = 0); // parent equal to zero in the header!
};
#endif // MY_GRAFIC_H_
