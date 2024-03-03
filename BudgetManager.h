#ifndef HEADER_DA5E5970ACF25108
#define HEADER_DA5E5970ACF25108

#include <iostream>
#include <vector>
#include "Type.h"
#include "Operation.h"
#include "DateMethods.h"

using namespace std;

class BudgetManager
{
    const int LOGGED_USER_ID;

    DateMethods dateMethods;

    vector <Operation> incomes;
    vector <Operation> expanses;

public:
    BudgetManager(int loggedUserId) : LOGGED_USER_ID(loggedUserId)
    {

    }

    void addOperation(const Type type);
    Operation typeOperationDetails();
    void showOperationDetails(Operation operation);
    void showIncomes();
    void showExpanses();
};
#endif // header guard

