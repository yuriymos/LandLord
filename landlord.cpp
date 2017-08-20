#include "landlord.h"
#include "my_graf_interface.h"
#include "base_classes.h"
/************************************************************/
landlord::landlord(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("LandLord");
    setFixedSize(440,240);

    //Create Buttons
    QPushButton * ptrEnterTenant = new QPushButton("&Enter a New Tenant", this);
    QPushButton * ptrEnterRent = new QPushButton("&Enter Rent", this);
    QPushButton * ptrEnterExpenses = new QPushButton("&Enter Expenses", this);
    QPushButton * ptrOutputTenants = new QPushButton("&Output List of the Tenants", this);
    QPushButton * ptrOutputIncome = new QPushButton("&Output the Table with Income", this);
    QPushButton * ptrOutputExpenses = new QPushButton("&Output the Table with Expenses", this);
    QPushButton * ptrAnnualReport = new QPushButton("&Annual Report", this);

    //Size of the Button setup
    ptrEnterTenant->setFixedSize(200,50);
    ptrEnterRent->setFixedSize(200,50);
    ptrEnterExpenses->setFixedSize(200,50);
    ptrOutputTenants->setFixedSize(200,50);
    ptrOutputIncome->setFixedSize(200,50);
    ptrOutputExpenses->setFixedSize(200,50);
    ptrAnnualReport->setFixedSize(415,50);

    //Connections setup
    connect(ptrEnterTenant, SIGNAL(clicked()), this, SLOT(slotEnterTenantClicked()));
    connect(ptrEnterRent, SIGNAL(clicked()), this, SLOT(slotEnterRentClicked()));
    connect(ptrEnterExpenses, SIGNAL(clicked()), this, SLOT(slotEnterExpensesClicked()));
    connect(ptrOutputTenants, SIGNAL(clicked()), this, SLOT(slotOutputTenantClicked()));
    connect(ptrOutputIncome, SIGNAL(clicked()), this, SLOT(slotOutputIncomeClicked()));
    connect(ptrOutputExpenses, SIGNAL(clicked()), this, SLOT(slotOutputExpensesClicked()));
    connect(ptrAnnualReport, SIGNAL(clicked()), this, SLOT(slotAnnualReportClicked()));

    //Layout setup
    QGridLayout * ptrLayout = new QGridLayout(this);
    ptrLayout->addWidget(ptrEnterTenant,0,0);
    ptrLayout->addWidget(ptrEnterRent,1,0);
    ptrLayout->addWidget(ptrEnterExpenses,2,0);
    ptrLayout->addWidget(ptrOutputTenants,0,1);
    ptrLayout->addWidget(ptrOutputIncome,1,1);
    ptrLayout->addWidget(ptrOutputExpenses,2,1);
    ptrLayout->addWidget(ptrAnnualReport,3,0,1,2,Qt::AlignCenter);

    setLayout(ptrLayout);

    // Create tenants' list
    ptrTList = new tenantList;
    ptrRRecord = new rentRecord;
    ptrExpenses = new expenseRecord;
    ptrAR = new annualReport(ptrRRecord, ptrExpenses);
}
/************************************************************/
landlord::~landlord()
{
    delete ptrTList;
    delete ptrRRecord;
    delete ptrExpenses;
    delete ptrAR;
}
/************************************************************/
void landlord::slotEnterTenantClicked()
{
    // We need to create a Dialog Window here.
    InputTenant * ptrInputTenant = new InputTenant;    
    if(ptrInputTenant->exec() == QDialog::Accepted)
    {
        // create a new tenant (dynamic)
        tenant * ptrTen = new tenant(ptrInputTenant->firstName(), ptrInputTenant->lastName(),
                                     (ptrInputTenant->roomNumber()).toInt());
        // add a tenant to the list
        ptrTList->insertTenant(ptrTen);
        delete ptrInputTenant;
    }
    else
    {
        delete ptrInputTenant;
    }
}
/************************************************************/
void landlord::slotEnterRentClicked()
{
    // We need to create a Dialog Window here.
    InputRent * ptrInputRent = new InputRent;
    if(ptrInputRent->exec() == QDialog::Accepted)
    {
        ptrRRecord->insertRent((ptrInputRent->roomNumber()).toInt(),
                               ptrInputRent->MonthOfYear(),
                               (ptrInputRent->Money()).toFloat());
        delete ptrInputRent;
    }
    else
    {
        delete ptrInputRent;
    }
}
/************************************************************/
void landlord::slotEnterExpensesClicked()
{
    // We need to create a Dialog Window here.
    InputExpenses * ptrInputExpenses = new InputExpenses;
    if(ptrInputExpenses->exec() == QDialog::Accepted)
    {
        // create a new expense (dynamic) &
        // send data from dialog window (class InputExpenses)
        expense * ptrExp = new expense(ptrInputExpenses->DayOfMonth(),
                                       ptrInputExpenses->anyMonth(),
                                       ptrInputExpenses->NameOrCompany(),
                                       ptrInputExpenses->anyCategory(),
                                       (ptrInputExpenses->Money()).toFloat());

        //expense * ptrExp = new expense(2,3,"defgvb","wgsf",5.6);
        // add a expense to the vector
        ptrExpenses->insertExp(ptrExp);
        delete ptrInputExpenses;
    }
    else
    {
        delete ptrInputExpenses;
    }
}
/************************************************************/
void landlord::slotOutputTenantClicked()
{
    OutputTenantList * ptrOutputTenants = new OutputTenantList(NULL, ptrTList);
    if(ptrOutputTenants->exec() == QDialog::Accepted)
    {
        // we should delete all QTableWidgetItem
        int tempAmount = ptrTList->howMany();
        QTableWidgetItem ** temp = ptrTList->display();
        for(int j = 0; j < 3*tempAmount; j++)
        {
            delete temp[j];
        }
        delete temp;
        delete ptrOutputTenants;
    }
}
/************************************************************/
void landlord::slotOutputIncomeClicked()
{
    OutputRentList * ptrOutputRents = new OutputRentList(NULL, ptrRRecord);
    if(ptrOutputRents->exec() == QDialog::Accepted)
    {
        // we should delete all QTableWidgetItem
        int tempAmount = ptrRRecord->howMany();
        QTableWidgetItem ** temp = ptrRRecord->display();
        for(int j = 0; j < 13*tempAmount; j++)
        {
            delete temp[j];
        }
        delete temp;
        delete ptrOutputRents;
    }

}
/************************************************************/
void landlord::slotOutputExpensesClicked()
{
    OutputExpensesList * ptrOutputExp = new OutputExpensesList(NULL, ptrExpenses);
    if(ptrOutputExp->exec() == QDialog::Accepted)
    {
        // we should delete all QTableWidgetItem
        const int COLUMNS = 4;
        int tempAmount = ptrExpenses->howMany();
        QTableWidgetItem ** temp = ptrExpenses->display();
        for(int j = 0; j < COLUMNS*tempAmount; j++)
        {
            delete temp[j];
        }
        delete temp;
        delete ptrOutputExp;
    }
}
/************************************************************/
void landlord::slotAnnualReportClicked()
{
    OutputAnnualReport * ptrOutputAnRep =
            new OutputAnnualReport(NULL, ptrAR);
    if(ptrOutputAnRep->exec() == QDialog::Accepted)
    {
        // we should delete all QTableWidgetItem
        const int COLUMNS = 2;
        int tempAmount = 9;
        QTableWidgetItem ** temp = ptrAR->display();
        for(int j = 0; j < COLUMNS*tempAmount; j++)
        {
            delete temp[j];
        }
        delete temp;
        delete ptrOutputAnRep;
    }
}
