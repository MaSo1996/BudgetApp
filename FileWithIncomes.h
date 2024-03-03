#ifndef HEADER_91A57FFD72D901F7
#define HEADER_91A57FFD72D901F7

#include <iostream>

#include "XmlFile.h"

using namespace std;

class FileWithIncomes : public XmlFile
{

public:
    FileWithIncomes(string nameOfFile) : XmlFile(nameOfFile)
    {

    }
};
#endif // header guard

