#ifndef HEADER_DA5E5970ACF25108
#define HEADER_DA5E5970ACF25108

#include <iostream>
#include <vector>
#include "Type.h"
#include "Operation.h"
#include "DateMethods.h"
#include "FileWithExpanses.h"
#include "FileWithIncomes.h"

using namespace std;

class BudgetManager
{
    const int LOGGED_USER_ID;

    DateMethods dateMethods;
    FileWithIncomes fileWithIncomes;

    vector <Operation> incomes;
    vector <Operation> expanses;

public:
    BudgetManager(int loggedUserId, string nameOfFile) : LOGGED_USER_ID(loggedUserId), fileWithIncomes(nameOfFile)
    {

    }

    void addOperation(const Type type);
    Operation typeOperationDetails();
    void showOperationDetails(Operation operation);
    void showIncomes();
    void showExpanses();
};
#endif // header guard

