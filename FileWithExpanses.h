#ifndef HEADER_28DACFD8828830B8
#define HEADER_28DACFD8828830B8

#include <iostream>

#include "XmlFile.h"

using namespace std;

class FileWithExpanses : public XmlFile
{

public:
    FileWithExpanses(string nameOfFile) : XmlFile(nameOfFile)
    {

    }
};
#endif // header guard

