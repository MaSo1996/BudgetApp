#ifndef HEADER_91A57FFD72D901F7
#define HEADER_91A57FFD72D901F7

#include <iostream>


#include "XmlFile.h"
#include "Markup.h"
#include "Operation.h"
#include "AuxilaryMethods.h"

using namespace std;

class FileWithIncomes : public XmlFile
{
    int lastIncomeId = 0;

public:
    FileWithIncomes(string nameOfFile) : XmlFile(nameOfFile)
    {

    }

    void addIncomeToTheFile(Operation operation);
    vector <Operation> loadIncomesFromFile(int loggedUserId);
    int getLastIncomeId();
};
#endif // header guard

