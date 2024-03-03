#include "XmlFile.h"

using namespace std;

bool XmlFile::checkIfFileIsEmpty(CMarkup & workingFile)
{
    if (workingFile.Load(NAME_OF_FILE))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

string XmlFile::getFileName()
{
    return NAME_OF_FILE;
}

void XmlFile::createFile(CMarkup & workingFile)
{
    workingFile.AddElem(NAME_OF_FILE);
    workingFile.Save(NAME_OF_FILE);
}
