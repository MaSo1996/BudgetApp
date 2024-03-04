#include "FileWithExpanses.h"

using namespace std;

void FileWithExpanses::addExpanseToTheFile(Operation operation)
{
    CMarkup workingFile;

    workingFile.ResetPos();

    if (!workingFile.Load(getFileName()))
    {
        workingFile.AddElem("Expanses");
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
        workingFile.FindElem("Expanses");
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
    lastExpanseId++;
}

vector <Operation> FileWithExpanses::loadExpansesFromTheFile(int loggedUserId)
{
    vector <Operation> expanses;
    CMarkup workingFile;
    MCD_STR strXML;

    workingFile.Load(getFileName());

    workingFile.FindElem("Expanses");

    workingFile.IntoElem();

    while (workingFile.FindElem("Operation"))
    {
        workingFile.IntoElem();

        Operation operation;
        workingFile.FindElem("id");
        strXML = workingFile.GetData();
        operation.id = stoi(strXML);

        lastExpanseId = operation.id;

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


        expanses.push_back(operation);
        workingFile.OutOfElem();
    }

    return expanses;
}

int FileWithExpanses::getLastExpanseId()
{
    return lastExpanseId;
}
