
#include <iostream>
#include <string>
#include "cash.h"


void Cash::printReceipt()
{
    cout << "Printing the cash receipt:\n";
    cout << "transactionId: " << transactionId << '\n';
    cout << "depositor: " << depositor << '\n';
    cout << "Date of cash Payment: " << date << '\n';
    cout << "Amount of transaction: " << amount << '\n';
    cout << "Bank employee who accepted the cash amount: " << bankEmployeeName << '\n';
    cout << "------------------------------------------------\n";
}