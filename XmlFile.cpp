#include "XmlFile.h"

using namespace std;

string XmlFile::getFileName()
{
    return NAME_OF_FILE;
}

void XmlFile::addOperationToFile(Operation operation, Type type)
{
    CMarkup workingFile;

    workingFile.ResetPos();

    if (!workingFile.Load(getFileName()))
    {
        switch (type)
        {
        case INCOME:
            workingFile.AddElem("Incomes");
            break;

        case EXPANSE:
            workingFile.AddElem("Expanses");
            break;
        }

        workingFile.IntoElem();
        workingFile.AddElem("Operation");
        workingFile.IntoElem();
        workingFile.AddElem("id",to_string(operation.id));
        workingFile.AddElem("userId",to_string(operation.userId));
        workingFile.AddElem("dateAsInt",to_string(operation.dateAsInt));
        workingFile.AddElem("date",operation.date);
        workingFile.AddElem("item",operation.item);
        workingFile.AddElem("amount",to_string(operation.amount));
        workingFile.RestorePos();
        workingFile.Save(getFileName());
    }

    else
    {
        switch (type)
        {
        case INCOME:
            workingFile.FindElem("Incomes");
            workingFile.IntoElem();
            break;

        case EXPANSE:
            workingFile.FindElem("Expanses");
            workingFile.IntoElem();
            break;
        }

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
        workingFile.RestorePos();
        workingFile.Save(getFileName());
    }

    lastOperationId++;
}

vector <Operation> XmlFile::loadOperationsFromFile(Type type, int loggedUserId)
{
    CMarkup workingFile;
    MCD_STR strXML;

    Operation operation;
    vector <Operation> operations;

    workingFile.Load(getFileName());

    switch (type)
    {
    case INCOME:
        workingFile.FindElem("Incomes");
        workingFile.IntoElem();
        break;

    case EXPANSE:
        workingFile.FindElem("Expanses");
        workingFile.IntoElem();
        break;
    }

    while(workingFile.FindElem("Operation"))
    {
        workingFile.IntoElem();

        workingFile.FindElem("id");
        strXML = workingFile.GetData();
        operation.id = stoi(strXML);

        workingFile.FindElem("userId ");
        strXML = workingFile.GetData();
        operation.userId = stoi(strXML);

        if (operation.userId == loggedUserId)
        {
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

            workingFile.OutOfElem();

            operations.push_back(operation);

            lastOperationId = operation.id;
        }
    }

    return operations;
}

int XmlFile::getLastOperationId()
{
    return lastOperationId;
}
