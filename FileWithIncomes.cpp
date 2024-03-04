#include "FileWithIncomes.h"

using namespace std;

void FileWithIncomes::addIncomeToTheFile(Operation operation)
{
    CMarkup workingFile;

    workingFile.ResetPos();

    if (!workingFile.Load(getFileName()))
    {
        workingFile.AddElem("Incomes");
        workingFile.IntoElem();
        workingFile.AddElem("Operation");
        workingFile.IntoElem();
        workingFile.AddElem("id",to_string(operation.id));
        workingFile.AddElem("userId",to_string(operation.userId));
        workingFile.AddElem("dateAsInt",to_string(operation.dateAsInt));
        workingFile.AddElem("date",operation.date);
        workingFile.AddElem("item",operation.item);
        workingFile.AddElem("amount",to_string(operation.amount));
        workingFile.ResetPos();
        workingFile.Save(getFileName());
    }

    else
    {
        workingFile.FindElem("Incomes");
        workingFile.IntoElem();

        while(workingFile.FindElem("Operation"))
        {

        }
        workingFile.AddElem("Operation");
        workingFile.IntoElem();
        workingFile.AddElem("id",to_string(operation.id));
        workingFile.AddElem("userId",to_string(operation.userId));
        workingFile.AddElem("dateAsInt",to_string(operation.dateAsInt));
        workingFile.AddElem("date",operation.date);
        workingFile.AddElem("item",operation.item);
        workingFile.AddElem("amount",to_string(operation.amount));
        workingFile.ResetPos();
        workingFile.Save(getFileName());
    }

    lastIncomeId++;
}

vector <Operation> FileWithIncomes::loadIncomesFromFile(int loggedUserId)
{
    vector <Operation> incomes;
    CMarkup workingFile;
    MCD_STR strXML;

    workingFile.Load(getFileName());

    workingFile.FindElem("Incomes");

    workingFile.IntoElem();

    while (workingFile.FindElem("Operation"))
    {
        workingFile.IntoElem();

        Operation operation;
        workingFile.FindElem("id");
        strXML = workingFile.GetData();
        operation.id = stoi(strXML);

        lastIncomeId = operation.id;

        workingFile.FindElem("userId");
        strXML = workingFile.GetData();
        operation.userId = stoi(strXML);

        if (operation.userId != loggedUserId)
        {
            workingFile.OutOfElem();
            continue;
        }

        workingFile.FindElem("dateAsInt");
        strXML = workingFile.GetData();
        operation.dateAsInt = stoi(strXML);

        workingFile.FindElem("date");
        strXML = workingFile.GetData();
        operation.date = strXML;

        workingFile.FindElem("item");
        strXML = workingFile.GetData();
        operation.item = strXML;

        workingFile.FindElem("amount");
        strXML = workingFile.GetData();
        operation.amount = stod(strXML);


        incomes.push_back(operation);
        workingFile.OutOfElem();
    }

    return incomes;
}

int FileWithIncomes::getLastIncomeId()
{
    return lastIncomeId;
}
