#ifndef HEADER_28DACFD8828830B8
#define HEADER_28DACFD8828830B8

#include <iostream>

#include "XmlFile.h"
#include "Markup.h"
#include "Operation.h"
#include "AuxilaryMethods.h"

using namespace std;

class FileWithExpanses : public XmlFile
{
    int lastExpanseId = 0;

public:
    FileWithExpanses(string nameOfFile) : XmlFile(nameOfFile)
    {

    }

    void addExpanseToTheFile(Operation operation);
    vector <Operation> loadExpansesFromTheFile(int loggedUserId);
    int getLastExpanseId();
};
#endif // header guard

