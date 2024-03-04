#ifndef HEADER_DA5E5970ACF25108
#define HEADER_DA5E5970ACF25108

#include <iostream>
#include <algorithm>
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
    FileWithExpanses fileWithExpanses;

    vector <Operation> incomes;
    vector <Operation> expanses;

public:
    BudgetManager(int loggedUserId, string nameOfFileWithIncomes, string nameOfFileWithExpanses) :
        LOGGED_USER_ID(loggedUserId),
        fileWithIncomes(nameOfFileWithIncomes),
        fileWithExpanses(nameOfFileWithExpanses)
    {
        loadOperationsFromFile(INCOME);
        loadOperationsFromFile(EXPANSE);
    }

    void addOperation(Type type);
    void loadOperationsFromFile(Type type);
    Operation typeOperationDetails(int lastOperationId);
    void showOperationDetails(Operation operation);
    void showOperationsFromChosenPeriod(string firstDate, string secondDate, vector <Operation> operations);
    double sumOperationsFromChosenPeriod(string firstDate, string secondDate, vector <Operation> operations);
    void showBalanceFromChosenPeriod(string firstDate, string secondDate);
    vector <Operation> createVectorOfOperationsFromChosenPeriod(string firstDate, string secondDate, vector <Operation> operations);
};
#endif // header guard

