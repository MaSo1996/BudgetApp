#include "BudgetManager.h"

using namespace std;

void BudgetManager::addOperation(const Type type)
{
    Operation operation;

    switch(type)
    {
    case INCOME:
        operation = typeOperationDetails(fileWithIncomes.getLastIncomeId());
        if (dateMethods.validateDate(operation.date))
        {
            incomes.push_back(operation);
            fileWithIncomes.addIncomeToTheFile(operation);
        }
        else
        {
            cout << "Incorrect date";
            getchar();
            return;
        }

        break;

    case EXPANSE:
        operation = typeOperationDetails(fileWithExpanses.getLastExpanseId());
        if (dateMethods.validateDate(operation.date))
        {
            expanses.push_back(operation);
            fileWithExpanses.addExpanseToTheFile(operation);
        }
        else
        {
            cout << "Incorrect date";
            getchar();
            return;
        }
        break;
    }
}

Operation BudgetManager::typeOperationDetails(int lastOperationId)
{
    Operation operation;

    operation.id = (lastOperationId + 1);
    operation.userId = LOGGED_USER_ID;
    cout << "Get curent date? Type 'y' for yest and 'n' for no: ";
    if (AuxilaryMethods::getChar() == 'y')
    {
        operation.date = dateMethods.getCurrentDate();
    }
    else if (AuxilaryMethods::getChar() == 'n')
    {
        operation.date = dateMethods.getDate();
    }
    operation.dateAsInt = dateMethods.convertDateStringToInt(operation.date);
    cout << "What was operation about: ";
    operation.item = AuxilaryMethods::readLine();
    cout << "What was amount of operation: ";
    operation.amount = AuxilaryMethods::readAmount();

    return operation;
}

void BudgetManager::showOperationDetails(Operation operation)
{
    cout << "Operation: " << operation.item << ", date: " << operation.date << ", amount: " << operation.amount << endl;
}

void BudgetManager::loadOperationsFromFile(Type type)
{
    switch (type)
    {
    case INCOME:
        incomes = fileWithIncomes.loadIncomesFromFile(LOGGED_USER_ID);
        break;
    case EXPANSE:
        expanses = fileWithExpanses.loadExpansesFromTheFile(LOGGED_USER_ID);
        break;
    }
}

void BudgetManager::showOperationsFromChosenPeriod(string firstDate, string secondDate, vector <Operation> operations)
{
    for (size_t i = 0; i < operations.size(); i++)
    {
        showOperationDetails(operations[i]);
    }
}

double BudgetManager::sumOperationsFromChosenPeriod(string firstDate, string secondDate, vector <Operation> operations)
{
    vector <Operation> customVector = createVectorOfOperationsFromChosenPeriod(firstDate,secondDate, operations);

    double sum = 0;

    for (size_t i = 0; i < customVector.size(); i++)
    {
        sum += customVector[i].amount;
    }

    return sum;
}

void BudgetManager::showBalanceFromChosenPeriod(string firstDate, string secondDate)
{
    vector <Operation> customIncomes = createVectorOfOperationsFromChosenPeriod(firstDate,secondDate,incomes);
    vector <Operation> customExpanses = createVectorOfOperationsFromChosenPeriod(firstDate,secondDate,expanses);

    double sumOfIncomes = sumOperationsFromChosenPeriod(firstDate,secondDate,customIncomes);
    double sumOfExpanses = sumOperationsFromChosenPeriod(firstDate,secondDate,customExpanses);

    sort(customIncomes.begin(),customIncomes.end());
    sort(customExpanses.begin(),customExpanses.end());

    showOperationsFromChosenPeriod(firstDate,secondDate,customIncomes);
    showOperationsFromChosenPeriod(firstDate,secondDate,customExpanses);

    cout << "Balance from: " << firstDate << " to: " << secondDate << ": " << (sumOfIncomes - sumOfExpanses) << endl;
    getchar();
}

vector <Operation> BudgetManager::createVectorOfOperationsFromChosenPeriod(string firstDate, string secondDate, vector <Operation> operations)
{
    vector <Operation> customOperations;

    for (size_t i = 0; i < operations.size(); i++)
    {
        if (operations[i].dateAsInt >= dateMethods.convertDateStringToInt(firstDate) && operations[i].dateAsInt <= dateMethods.convertDateStringToInt(secondDate))
        {
            customOperations.push_back(operations[i]);
        }
    }

    return customOperations;
}

