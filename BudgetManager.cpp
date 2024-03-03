#include "BudgetManager.h"

using namespace std;

void BudgetManager::addOperation(const Type type)
{
    switch(type)
    {
    case EXPANSE:
        expanses.push_back(typeOperationDetails());
        break;
    case INCOME:
        incomes.push_back(typeOperationDetails());
        break;
    }
}

Operation BudgetManager::typeOperationDetails()
{
    Operation operation;

    operation.date = dateMethods.getDate();
    operation.dateAsInt = dateMethods.convertDateStringToInt(operation.date);
    cout << "What was operation about: ";
    operation.item = AuxilaryMethods::readLine();
    cout << "What was amount of operation: ";
    operation.amount = AuxilaryMethods::readAmount();

    return operation;
}

void BudgetManager::showOperationDetails(Operation operation)
{
    cout << "Date of operation: " << operation.date << endl;
    cout << "Amount of operation: " << operation.amount << endl;
    cout << "What was operation about: " << operation.item << endl;
}

void BudgetManager::showIncomes()
{
    for (size_t i = 0; i < incomes.size(); i++)
    {
        showOperationDetails(incomes[i]);
    }
}

void BudgetManager::showExpanses()
{
    for (size_t i = 0; i < expanses.size(); i++)
    {
        showOperationDetails(expanses[i]);
    }
}
