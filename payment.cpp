

#include "payment.h"
using namespace std;

Payment::Payment()
{
    amount = 0;
    successStatus = false;
}

bool Payment::carryOutTransaction(int _id, string dep, string coll, string dt, int amount = 0)
{
    if (amount <= 0)
    {
        cout << "Amount involved in the transaction is not allowed!!";
        return false;
    }

    try
    {
        transactionId = _id;
        depositor = dep;
        collector = coll;
        date = dt;
        this->amount = amount;
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}