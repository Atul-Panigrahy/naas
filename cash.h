#ifndef CASH_H
#define CASH_H

#include <string>
#include <iostream>
#include "payment.h"
using namespace std;

class Cash : public Payment
{
public:
    int bankEmployeeName;

    void printReceipt();
};

#endif // CASH_H