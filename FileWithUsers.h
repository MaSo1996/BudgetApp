#ifndef HEADER_281042808DCC7DCE
#define HEADER_281042808DCC7DCE

#include <iostream>
#include <vector>
#include "XmlFile.h"
#include "User.h"

using namespace std;

class FileWithUsers : public XmlFile
{
    int lastUserId = 0;

public:
    FileWithUsers(string nameOfFile) : XmlFile(nameOfFile)
    {

    }

    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void updatingUserData(User userToUpdate);

    int getLastUserId();
};

#endif // header guard

