#ifndef HEADER_F204A1E7F4E7177E
#define HEADER_F204A1E7F4E7177E

#include <iostream>
#include <vector>

#include "Markup.h"
#include "Operation.h"
#include "Type.h"

using namespace std;

class XmlFile
{
    const string NAME_OF_FILE;

public:
    XmlFile(string nameOfFile) : NAME_OF_FILE(nameOfFile)
    {

    }

    string getFileName();
};

#endif // header guard

