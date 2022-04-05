
#include <iostream>
#include <string>
#include "cheque.h"

/*
    int chequeNumber;
    void PrintInvoice();
*/

void Cheque::PrintInvoice()
{
    cout << "Printing the cash invoice:\n";
    cout << "transactionId: " << transactionId << '\n';
    cout << "Cheque Number: " << chequeNumber;
    cout << "depositor: " << depositor << '\n';
    cout << "Date of Payment: " << date << '\n';
    cout << "Amount of transaction: " << amount << '\n';
    cout << "------------------------------------------------\n";
}