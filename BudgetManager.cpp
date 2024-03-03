#include "BudgetManager.h"

using namespace std;

void BudgetManager::addOperation(const Type type)
{
    Operation operation;

    switch(type)
    {
    case INCOME:
        operation = typeOperationDetails(fileWithIncomes.getLastOperationId());
        incomes.push_back(operation);
        fileWithIncomes.addOperationToFile(operation,type);
        break;

    case EXPANSE:
        operation = typeOperationDetails(fileWithExpanses.getLastOperationId());
        expanses.push_back(operation);
        fileWithExpanses.addOperationToFile(operation,type);
        break;
    }
}

Operation BudgetManager::typeOperationDetails(int lastOperationId)
{
    Operation operation;

    operation.id = (lastOperationId + 1);
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

void BudgetManager::loadOperationsFromFile(const Type type)
{
    switch (type)
    {
    case INCOME:
        incomes = fileWithIncomes.loadOperationsFromFile(type);
        break;
    case EXPANSE:
        expanses = fileWithExpanses.loadOperationsFromFile(type);
        break;
    }
}
