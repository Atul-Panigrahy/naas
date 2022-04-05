#ifndef CHEQUE_H
#define CHEQUE_H

#include <string>
#include <iostream>
#include "payment.h"
using namespace std;

class Cheque : public Payment
{
public:
    int chequeNumber;
    void PrintInvoice();
};

#endif // CHEQUE_H