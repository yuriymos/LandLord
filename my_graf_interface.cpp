#include "my_graf_interface.h"
/*****************************************************************/
// these are the methods of the InputTenant class
InputTenant::InputTenant(QWidget *parent)
    : QDialog(parent, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
    setFixedSize(270,130);
    setWindowTitle("Enter a Tenant");

    ptrFirstName = new QLineEdit(this);
    ptrLastName = new QLineEdit(this);
    ptrAptNumber = new QComboBox(this);

    // this is a list with room numbers
    QStringList lst;
    lst << "101" << "102" << "103" << "104"
        << "201" << "202" << "203" << "204"
        << "301" << "302" << "303" << "304";
    ptrAptNumber->addItems(lst);

    QLabel * ptrLabelFN = new QLabel("&First Name", this);
    QLabel * ptrLabelLN = new QLabel("&Last Name", this);
    QLabel * ptrLabelNo = new QLabel("&Room Namber", this);
    ptrLabelFN->setBuddy(ptrFirstName);
    ptrLabelLN->setBuddy(ptrLastName);
    ptrLabelNo->setBuddy(ptrAptNumber);


    // Validation
    NameValidator * ptrNValidator = new NameValidator(this);
    ptrFirstName->setValidator(ptrNValidator);
    ptrLastName->setValidator(ptrNValidator);

    // Create buttons Ok & Cancel
    QPushButton * ptrOk = new QPushButton("&Ok", this);
    QPushButton * ptrCancel = new QPushButton("&Cancel", this);
    ptrOk->setFixedSize(80,25);
    ptrCancel->setFixedSize(80,25);

    connect(ptrOk, SIGNAL(clicked(bool)), this, SLOT(accept()));
    connect(ptrCancel, SIGNAL(clicked(bool)), this, SLOT(reject()));

    // Layout setup
    QGridLayout * ptrGridLayout = new QGridLayout(this);
    ptrGridLayout->addWidget(ptrLabelFN,0,0);
    ptrGridLayout->addWidget(ptrLabelLN,1,0);
    ptrGridLayout->addWidget(ptrLabelNo,2,0);
    ptrGridLayout->addWidget(ptrFirstName,0,1);
    ptrGridLayout->addWidget(ptrLastName,1,1);
    ptrGridLayout->addWidget(ptrAptNumber,2,1);
    ptrGridLayout->addWidget(ptrOk,3,0);
    ptrGridLayout->addWidget(ptrCancel,3,1);
    setLayout(ptrGridLayout);

    QDialog::setModal(true);
    show();
}
// to get a first name of the tenant
QString InputTenant::roomNumber() const
{
    return ptrAptNumber->currentText();
}
// to get a first name of the tenant
QString InputTenant::firstName() const
{
    return ptrFirstName->text();
}
// to get a last name of the tenant
QString InputTenant::lastName() const
{
    return ptrLastName->text();
}
/*****************************************************************/
// these are the methods of the InputRent class
InputRent::InputRent(QWidget *parent)
    : QDialog(parent, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
    setFixedSize(270,130);
    setWindowTitle("Enter Rent, Please");

    ptrAptNumber = new QComboBox(this);
    ptrMonth = new QComboBox(this);
    ptrMoney = new QLineEdit(this);

    // this is a list with room numbers
    QStringList lst;
    lst << "101" << "102" << "103" << "104"
        << "201" << "202" << "203" << "204"
        << "301" << "302" << "303" << "304";
    ptrAptNumber->addItems(lst);

    // this is a list with months
    lst.clear();
    lst << "January" << "February" << "March"
        << "April" << "May" << "June" << "July"
        << "August" << "September" << "October"
        << "November" << "December";
    ptrMonth->addItems(lst);

    QLabel * ptrLabelNo = new QLabel("&Room Namber", this);
    ptrLabelNo->setBuddy(ptrAptNumber);
    QLabel * ptrEnrMonth = new QLabel("&Choose a Month", this);
    ptrEnrMonth->setBuddy(ptrMonth);
    QLabel * ptrEnrMoney = new QLabel("&Enter Money", this);
    ptrEnrMoney->setBuddy(ptrMoney);

    // Validation
    //QDoubleValidator * ptrQDoubleValidator = new QDoubleValidator(this);
    //ptrMoney->setValidator(ptrQDoubleValidator);

    // Create buttons Ok & Cancel
    QPushButton * ptrOk = new QPushButton("&Ok", this);
    QPushButton * ptrCancel = new QPushButton("&Cancel", this);
    ptrOk->setFixedSize(80,25);
    ptrCancel->setFixedSize(80,25);

    connect(ptrOk, SIGNAL(clicked(bool)), this, SLOT(accept()));
    connect(ptrCancel, SIGNAL(clicked(bool)), this, SLOT(reject()));

    // Layout setup
    QGridLayout * ptrGridLayout = new QGridLayout(this);
    ptrGridLayout->addWidget(ptrLabelNo,0,0);
    ptrGridLayout->addWidget(ptrEnrMonth,1,0);
    ptrGridLayout->addWidget(ptrEnrMoney,2,0);

    ptrGridLayout->addWidget(ptrAptNumber,0,1);
    ptrGridLayout->addWidget(ptrMonth,1,1);
    ptrGridLayout->addWidget(ptrMoney,2,1);

    ptrGridLayout->addWidget(ptrOk,3,0);
    ptrGridLayout->addWidget(ptrCancel,3,1);
    setLayout(ptrGridLayout);

    QDialog::setModal(true);
    show();
}

// to get a last name of the tenant
QString InputRent::roomNumber() const
{
    return ptrAptNumber->currentText();
}
 // to get a days of a week
int InputRent::MonthOfYear() const
{
    return ptrMonth->currentIndex();
}
// to get a rent
QString InputRent::Money() const
{
    return ptrMoney->text();
}
/*****************************************************************/
// these are the methods of the InputExpenses class
InputExpenses::InputExpenses(QWidget *parent)
    : QDialog(parent, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
    setFixedSize(270,170);
    setWindowTitle("Enter Expenses, Please");

    ptrDayOfMonth = new QComboBox(this);
    ptrMonth = new QComboBox(this);
    ptrNameOrCompany = new QLineEdit(this);
    ptrMoney = new QLineEdit(this);
    ptrCategory = new QComboBox(this);

    // this is a list with months
    QStringList lst;
    for(int j = 1; j < 32; j++)
    {
        //QString str = QString::number(j);
        lst << QString::number(j);
    }
    ptrDayOfMonth->addItems(lst);

    lst.clear();
    lst << "January" << "February" << "March"
        << "April" << "May" << "June" << "July"
        << "August" << "September" << "October"
        << "November" << "December";
    ptrMonth->addItems(lst);

    /*
    lst.clear();
    lst << "First Megabank" << "City Water" << "Steady State"
        << "P.G. & E." << "Sam's HardWare" << "Ernie Glotz"
        << "Plotx & Skeems" << "Country of Springfield"
        << "Gotham Courier" << "Acme Painting";
    qSort(lst.begin(),lst.end()); // to sort the list
    ptrNameOrCompany->addItems(lst);
    */

    lst.clear();
    lst << "Mortgage" << "Utilities" << "Insurance"
        << "Supplies" << "Legal Fees" << "Property Texes"
        << "Advertising" << "Repairs" << "Maintainance";
    qSort(lst.begin(),lst.end()); // to sort the list
    ptrCategory->addItems(lst);

    QLabel * ptrLabelDay = new QLabel("&Choose a Date", this);
    ptrLabelDay->setBuddy(ptrDayOfMonth);
    QLabel * ptrLabelMonth = new QLabel("&Choose a Month", this);
    ptrLabelMonth->setBuddy(ptrMonth);
    QLabel * ptrLabelCompany = new QLabel("&Choose a Company", this);
    ptrLabelCompany->setBuddy(ptrNameOrCompany);
    QLabel * ptrEnrMoney = new QLabel("&Enter Money", this);
    ptrEnrMoney->setBuddy(ptrMoney);
    QLabel * ptrLabelCategory = new QLabel("&Choose a Category", this);
    ptrLabelCategory->setBuddy(ptrCategory);

    // Validation
    NameValidator * ptrNValidator = new NameValidator(this);
    ptrNameOrCompany->setValidator(ptrNValidator);

    // Create buttons Ok & Cancel
    QPushButton * ptrOk = new QPushButton("&Ok", this);
    QPushButton * ptrCancel = new QPushButton("&Cancel", this);
    ptrOk->setFixedSize(80,25);
    ptrCancel->setFixedSize(80,25);

    connect(ptrOk, SIGNAL(clicked(bool)), this, SLOT(accept()));
    connect(ptrCancel, SIGNAL(clicked(bool)), this, SLOT(reject()));

    // Layout setup
    QGridLayout * ptrGridLayout = new QGridLayout(this);
    ptrGridLayout->addWidget(ptrLabelDay,0,0);
    ptrGridLayout->addWidget(ptrLabelMonth,1,0);
    ptrGridLayout->addWidget(ptrLabelCompany,2,0);
    ptrGridLayout->addWidget(ptrLabelCategory,3,0);
    ptrGridLayout->addWidget(ptrEnrMoney,4,0);

    ptrGridLayout->addWidget(ptrDayOfMonth,0,1);
    ptrGridLayout->addWidget(ptrMonth,1,1);
    ptrGridLayout->addWidget(ptrNameOrCompany,2,1);
    ptrGridLayout->addWidget(ptrCategory,3,1);
    ptrGridLayout->addWidget(ptrMoney,4,1);

    ptrGridLayout->addWidget(ptrOk,5,0);
    ptrGridLayout->addWidget(ptrCancel,5,1);
    setLayout(ptrGridLayout);

    QDialog::setModal(true);
    show();
}
// to get a day
int InputExpenses::DayOfMonth() const
{
    return ptrDayOfMonth->currentIndex();
}
// to get a Month
int InputExpenses::anyMonth() const
{
    return ptrMonth->currentIndex();
}
// to get a person's name or a company
QString InputExpenses::NameOrCompany() const
{
     return ptrNameOrCompany->text();
}
// to get a Expense
QString InputExpenses::Money() const
{
    return ptrMoney->text();
}
// to get a Category
QString InputExpenses::anyCategory() const
{
    return ptrCategory->currentText();
}
/*****************************************************************/
// these are the methods of the OutputTenantList class
OutputTenantList::OutputTenantList(QWidget *parent, tenantList * ptrTL)
    : QDialog(parent, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
    setFixedSize(350,440);
    setWindowTitle("The Tenant List");

    //Create a table with tenants

    const int COLUMNS = 3;
    int rows = ptrTL->howMany();
    QTableWidget * ptrQTableWidget = new QTableWidget(rows, COLUMNS, this);

    QStringList lst;
    lst << "Room Number" << "First Name" << "Last Name";
    ptrQTableWidget->setHorizontalHeaderLabels(lst);

    QTableWidgetItem ** temp = ptrTL->display();
    int tempAmount = ptrTL->howMany();

    for(int j = 0; j < 3*tempAmount; j++)
    {
        temp[j]->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ptrQTableWidget->setItem(j/3,j%3,temp[j]);
    }
    // Create buttons Ok & Cancel
    QPushButton * ptrOk = new QPushButton("&Ok", this);
    ptrOk->setFixedSize(80,25);
    connect(ptrOk, SIGNAL(clicked(bool)), this, SLOT(accept()));

    // Layout setup
    QGridLayout * ptrGridLayout = new QGridLayout(this);
    ptrGridLayout->addWidget(ptrQTableWidget,0,0);
    ptrGridLayout->addWidget(ptrOk,1,0);
    setLayout(ptrGridLayout);

    QDialog::setModal(true);
    show();
}
/*****************************************************************/
// these are the methods of the OutputRentList class
OutputRentList::OutputRentList(QWidget *parent, rentRecord * ptrRR)
    : QDialog(parent, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
    setFixedSize(990,440);
    setWindowTitle("The Rent List");

    //Create a table with tenants
    QTableWidget * ptrQTableWidget = new QTableWidget(12,13,this);
    ptrQTableWidget->setColumnWidth(0,100);
    for(int j = 1; j < 13; j++)
    {
        ptrQTableWidget->setColumnWidth(j,70);
    }

    QStringList lst;
    lst << "Room Number" << "January" << "February" << "March"
        << "April" << "May" << "June" << "July"
        << "August" << "September" << "October"
        << "November" << "December";
    ptrQTableWidget->setHorizontalHeaderLabels(lst);

    QTableWidgetItem ** temp = ptrRR->display();
    int tempAmount = ptrRR->howMany();

    for(int j = 0; j < 13*tempAmount; j++)
    {
        temp[j]->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        temp[j]->setTextAlignment(Qt::AlignCenter);
        ptrQTableWidget->setItem(j/13,j%13,temp[j]);
    }

    // Create buttons Ok & Cancel
    QPushButton * ptrOk = new QPushButton("&Ok", this);
    ptrOk->setFixedSize(80,25);
    connect(ptrOk, SIGNAL(clicked(bool)), this, SLOT(accept()));

    // Layout setup
    QGridLayout * ptrGridLayout = new QGridLayout(this);
    ptrGridLayout->addWidget(ptrQTableWidget,0,0);
    ptrGridLayout->addWidget(ptrOk,1,0);
    setLayout(ptrGridLayout);

    QDialog::setModal(true);
    show();
}
/*****************************************************************/
// these are the methods of the OutputExpensesList class
OutputExpensesList::OutputExpensesList(QWidget *parent, expenseRecord * ptrExp)
    : QDialog(parent, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
    setFixedSize(525,440);
    setWindowTitle("The Expenses List");

    //Create a table with tenants
    const int COLUMNS = 4;
    int rows = ptrExp->howMany();
    QTableWidget * ptrQTableWidget = new QTableWidget(rows, COLUMNS, this);
    ptrQTableWidget->setColumnWidth(0,70);
    for(int j = 1; j < COLUMNS; j++)
    {
        ptrQTableWidget->setColumnWidth(j,130);
    }

    QStringList lst;
    lst << "Date" << "Payee" << "Sum" << "Category";
    ptrQTableWidget->setHorizontalHeaderLabels(lst);

    QTableWidgetItem ** temp = ptrExp->display();
    int tempAmount = ptrExp->howMany();

    for(int j = 0; j < COLUMNS*tempAmount; j++)
    {
        temp[j]->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        temp[j]->setTextAlignment(Qt::AlignCenter);
        ptrQTableWidget->setItem(j/COLUMNS,j%COLUMNS,temp[j]);
    }

    // Create buttons Ok & Cancel
    QPushButton * ptrOk = new QPushButton("&Ok", this);
    ptrOk->setFixedSize(80,25);
    connect(ptrOk, SIGNAL(clicked(bool)), this, SLOT(accept()));

    // Layout setup
    QGridLayout * ptrGridLayout = new QGridLayout(this);
    ptrGridLayout->addWidget(ptrQTableWidget,0,0);
    ptrGridLayout->addWidget(ptrOk,1,0);
    setLayout(ptrGridLayout);

    QDialog::setModal(true);
    show();
}
/*****************************************************************/
// this class allows to create an interface of the annual report
OutputAnnualReport::OutputAnnualReport(QWidget * parent, annualReport * ptrAnRep)
    : QDialog(parent, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
    setFixedSize(340,350);
    setWindowTitle("The Annual Report");

    //Create a table with tenants
    const int COLUMNS = 2;
    //int rowsRR = ptrRR->howMany();
    //int rowsExp = ptrExp->howMany();
    QTableWidget * ptrQTableWidget = new QTableWidget( 9, COLUMNS, this);
    ptrQTableWidget->setColumnWidth(0,150);
    ptrQTableWidget->setColumnWidth(0,200);

    QTableWidgetItem ** temp = ptrAnRep->display();
    //int tempAmount = ptrExp->howMany();

    for(int j = 0; j < COLUMNS*9; j++)
    {
        temp[j]->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        temp[j]->setTextAlignment(Qt::AlignCenter);
        ptrQTableWidget->setItem(j/COLUMNS,j%COLUMNS,temp[j]);
    }

    // Create buttons Ok & Cancel
    QPushButton * ptrOk = new QPushButton("&Ok", this);
    ptrOk->setFixedSize(80,25);
    connect(ptrOk, SIGNAL(clicked(bool)), this, SLOT(accept()));

    // Layout setup
    QGridLayout * ptrGridLayout = new QGridLayout(this);
    ptrGridLayout->addWidget(ptrQTableWidget,0,0);
    ptrGridLayout->addWidget(ptrOk,1,0);
    setLayout(ptrGridLayout);

    QDialog::setModal(true);
    show();
}
