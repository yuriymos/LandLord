#ifndef LANDLORD_H
#define LANDLORD_H

#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QMessageBox>
#include <QValidator>
#include <QDoubleValidator>
#include <QTableWidget>
#include "base_classes.h"

class landlord : public QWidget
{
    Q_OBJECT

private:
    tenantList * ptrTList;
    rentRecord * ptrRRecord;
    expenseRecord * ptrExpenses;
    annualReport * ptrAR;
public:
    landlord(QWidget *parent = 0);
    ~landlord();
public slots:
    void slotEnterTenantClicked();
    void slotEnterRentClicked();
    void slotEnterExpensesClicked();
    void slotOutputTenantClicked();
    void slotOutputIncomeClicked();
    void slotOutputExpensesClicked();
    void slotAnnualReportClicked();

};

#endif // LANDLORD_H
