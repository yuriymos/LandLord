#include "base_classes.h"
/*****************************************************************/
// this is a class for each tenant
tenant::tenant(QString Fn, QString Ln, int aNo) : FirstName(Fn), LastName(Ln), aptNumber(aNo)
{
    // it is empty here
}
tenant::~tenant()
{
    // it is empty here
}
int tenant::getAptNumber() const
{
    return aptNumber;
}
QString tenant::FtName() const
{
    return FirstName;
}
QString tenant::LtName() const
{
    return LastName;
}
// The functions for a set
bool operator < (const tenant& t1, const tenant& t2)
{
    return t1.aptNumber < t2.aptNumber;
}
bool operator == (const tenant& t1, const tenant& t2)
{
    return t1.aptNumber == t2.aptNumber;
}
/*****************************************************************/
// this is a class for a functional object in order to compare tenants
bool compareTenants::operator() (tenant* ptrT1, tenant* ptrT2) const
{
    return *ptrT1 < *ptrT2;
}
/*****************************************************************/
// this is a class to create a list of the tenants
tenantList::~tenantList()
{
    while(!setptrTens.empty())
    {
        iter = setptrTens.begin();
        delete *iter;
        setptrTens.erase(iter);
    }
}
void tenantList::insertTenant(tenant* ptrT)
{
    setptrTens.insert(ptrT);
}
// Is the name in the list?
int tenantList::getAptNo(QString FName, QString LName)
{
    int aptNo;
    tenant dummy(FName, LName,0);
    iter = setptrTens.begin();
    while(iter != setptrTens.end())
    {
        aptNo = (*iter)->getAptNumber();
        if(dummy == **iter++)
            return aptNo;
    }
    return -1;
}
// how many tenants are?
int tenantList::howMany() const
{
    return setptrTens.size();
}
// display the list of tenants
QTableWidgetItem** tenantList::display()
{
    int temp =3*howMany();
    int counter = 0;

    QTableWidgetItem** pTemp = new QTableWidgetItem* [temp];

    iter = setptrTens.begin();

    while(iter != setptrTens.end())
    {
        // thus we create each element of the array
        // we need to delete it after using!
        QString str;
        str.setNum((*iter)->getAptNumber());
        pTemp[3*counter+0] = new QTableWidgetItem (str);
        pTemp[3*counter+1] = new QTableWidgetItem ((*iter)->FtName());
        pTemp[3*counter+2] = new QTableWidgetItem ((*iter)->LtName());
        counter++;
        iter++;
    }
    return pTemp;
}
/*****************************************************************/
// this is a class for a row of a table with rent
rentRow::rentRow(int an) : aptNumber(an)
{
    fill(&rent[0], &rent[12], 0);
}
// enter month and money
void rentRow::setRent(int m, float am)
{
    rent[m] = am;
}
// destructor
rentRow::~rentRow()
{
    // it is empty here
}
// this function returns sum of rent for each row
float rentRow::getSumOfRow()
{
    float temp = 0;
    for(int j = 0; j < 12; j++)
    {
        temp += rent[j];
    }
    return temp;
    //return accumulate(&rent[0], &rent[12], 0);
}

int rentRow::getAptNumber() const
{
    return aptNumber;
}
float rentRow::getRent(int mn) const
{
    return rent[mn];
}
// The functions for a set
bool operator < (const rentRow& t1, const rentRow& t2)
{
    return t1.aptNumber < t2.aptNumber;
}
bool operator == (const rentRow& t1, const rentRow& t2)
{
    return t1.aptNumber == t2.aptNumber;
}
/*****************************************************************/
// this is a class for a functional object in order to objects rentRow
bool compareRows::operator() (rentRow* ptrR1, rentRow* ptrR2) const
{
    return *ptrR1 < *ptrR2;
}
/*****************************************************************/
// this is a class to create a list of the rentRows
rentRecord::~rentRecord()
{
    while(!setptrRR.empty())
    {
        iter = setptrRR.begin();
        delete *iter;
        setptrRR.erase(iter);
    }
}

void rentRecord::insertRent(int aptNo, int month, float amount)
{
    // create a template object of the rentRow class with current number
    rentRow searchRow(aptNo);
    iter = setptrRR.begin();
    while(iter != setptrRR.end())
    {
        if(searchRow == **iter)
        {
            (*iter)->setRent(month, amount);
            return; // it is a good way to leave the function
        }
        else
            iter++;
    }
    rentRow* ptrRow = new rentRow(aptNo);
    ptrRow->setRent(month, amount);
    setptrRR.insert(ptrRow);
}
// sum all rental payments
float rentRecord::getSumOfRents()
{
    float sumRents = 0.0;
    iter = setptrRR.begin();
    while(iter != setptrRR.end())
    {
        sumRents += (*iter)->getSumOfRow();
        iter++;
    }
    return sumRents;
}
// how many rows are?
int rentRecord::howMany() const
{
    return setptrRR.size();
}
// display the list of rows
QTableWidgetItem** rentRecord::display()
{
    int temp = 13*howMany();
    int counter = 0;

    QTableWidgetItem** pTemp = new QTableWidgetItem* [temp];

    iter = setptrRR.begin();

    while(iter != setptrRR.end())
    {
        // thus we create each element of the array
        // we need to delete it after using!

        QString str;
        str.setNum((*iter)->getAptNumber()); // convert to QString
        pTemp[13*counter+0] = new QTableWidgetItem (str);
        for(int j = 1; j < 13; j++)
        {
            str.setNum((*iter)->getRent(j-1));
            pTemp[13*counter+j] = new QTableWidgetItem (str);
        }

        counter++;
        iter++;
    }
    return pTemp;
}
/*****************************************************************/
// this is a class for a row of a table with expenses
QString expense::getDate() const
{
    QString temp1, temp2;
    temp1.setNum(month + 1);
    temp2.setNum(day + 1);
    return (temp1 + "/" + temp2);
}
QString expense::getPayee() const
{
    return payee;
}
float expense::getAmount() const
{
    return amount;
}
QString expense::getCategory() const
{
    return category;
}
bool operator < (const expense& e1, const expense& e2)
{
    if(e1.month == e2.month)
        return e1.day < e2.day;
    else
        return e1.month < e2.month;
}
bool operator == (const expense& e1, const expense& e2)
{
    return (e1.month == e2.month && e1.day == e2.day);
}
/*****************************************************************/
// this is a class for a functional object in order to objects expense
bool compareDates::operator() (expense* ptrE1, expense* ptrE2) const
{
    return *ptrE1 < *ptrE2;
}
/*****************************************************************/
// this is a class for a functional object in order to objects expense
bool compareCategories::operator() (expense* ptrE1, expense* ptrE2) const
{
    return ptrE1->getCategory() < ptrE2->getCategory();
}
/*****************************************************************/
// this is a class to create a vector of the expenses
expenseRecord::~expenseRecord()
{
    while( !vectPtrExpenses.empty() )
    {
        iter = vectPtrExpenses.begin();
        delete *iter;
        vectPtrExpenses.erase(iter);
    }
}
void expenseRecord::insertExp(expense* ptrEXP)
{
    // the program hasn't worked therefore
    // I haven,t create vector in the constructor.
    vectPtrExpenses.push_back(ptrEXP);
}
// how many rows are?
int expenseRecord::howMany() const
{
    return vectPtrExpenses.size();
}
// sum all expenses
float expenseRecord::getSumOfExpenses()
{
    float totalExpenses = 0;
    if(vectPtrExpenses.size() == 0)
    {
        return 0;
    }
    // sort by categories
    sort(vectPtrExpenses.begin(), vectPtrExpenses.end(), compareCategories());
    // sum by eath category
    iter = vectPtrExpenses.begin();
    QString tempCat = (*iter)->getCategory();
    float sumCat = 0.0;

    while(iter != vectPtrExpenses.end())
    {
        if(tempCat == (*iter)->getCategory())
        {
            sumCat += (*iter)->getAmount();
        }
        else
        {
            totalExpenses += sumCat;
            tempCat = (*iter)->getCategory();
            sumCat = (*iter)->getAmount();
        }
        iter++;
    } // end while
    totalExpenses += sumCat;
    return totalExpenses;
}
// display the vector of expenses
QTableWidgetItem** expenseRecord::display()
{
    const int COLUMNS = 4;
    int temp = COLUMNS*howMany();
    int counter = 0;

    QTableWidgetItem** pTemp = new QTableWidgetItem* [temp];

    iter = vectPtrExpenses.begin();

    while(iter != vectPtrExpenses.end())
    {
        // thus we create each element of the array
        // we need to delete it after using!
        QString str;
        str.setNum((*iter)->getAmount());  // convert to QString
        pTemp[COLUMNS*counter+0] = new QTableWidgetItem ((*iter)->getDate());
        pTemp[COLUMNS*counter+1] = new QTableWidgetItem ((*iter)->getPayee());
        pTemp[COLUMNS*counter+2] = new QTableWidgetItem (str);
        pTemp[COLUMNS*counter+3] = new QTableWidgetItem ((*iter)->getCategory());
        counter++;
        iter++;
    }
    return pTemp;
}
/*****************************************************************/
// this is a class to create an annual Report
annualReport::annualReport(rentRecord* pRR, expenseRecord* pER) :
    ptrRR(pRR), ptrER(pER)
{
    // it is empty here
}
QTableWidgetItem** annualReport::display()
{
    const int COLUMNS = 2;
    int temp = COLUMNS*9;
    int counter = 0;

    QTableWidgetItem** pTemp = new QTableWidgetItem* [temp];
    pTemp[0] = new QTableWidgetItem ("INCOME");
    pTemp[1] = new QTableWidgetItem ("");
    pTemp[2] = new QTableWidgetItem ("Rent");
    float tempRents = ptrRR->getSumOfRents();
    QString str;
    str.setNum(tempRents);  // convert to QString
    pTemp[3] = new QTableWidgetItem (str);
    pTemp[4] = new QTableWidgetItem ("TOTAL INCOME");
    pTemp[5] = new QTableWidgetItem (str);

    pTemp[6] = new QTableWidgetItem ("");
    pTemp[7] = new QTableWidgetItem ("");
    pTemp[8] = new QTableWidgetItem ("EXPENSES");
    pTemp[9] = new QTableWidgetItem ("");
    pTemp[10] = new QTableWidgetItem ("Expenses");
    float tempExpenses = ptrER->getSumOfExpenses();
    str.clear();
    str.setNum(tempExpenses);  // convert to QString
    pTemp[11] = new QTableWidgetItem (str);
    pTemp[12] = new QTableWidgetItem ("TOTAL EXPENSES");
    pTemp[13] = new QTableWidgetItem (str);
    pTemp[14] = new QTableWidgetItem ("");
    pTemp[15] = new QTableWidgetItem ("");
    pTemp[16] = new QTableWidgetItem ("NET PROFIT or (LOSS)");
    str.clear();
    float result = tempRents - tempExpenses;
    str.setNum(result);  // convert to QString
    result >= 0 ? pTemp[17] = new QTableWidgetItem (str) :
            pTemp[17] = new QTableWidgetItem ("(" + str + ")");
    return pTemp;
}
