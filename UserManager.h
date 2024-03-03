#ifndef HEADER_52185F2B2B857920
#define HEADER_52185F2B2B857920

#include <iostream>
#include <vector>

#include "User.h"
#include "AuxilaryMethods.h"
#include "FileWithUsers.h"

class UserManager
{
    vector <User> users;
    FileWithUsers fileWithUsers;
    int loggedUserId = 0;

public:
    UserManager(string nameOfFile) : fileWithUsers(nameOfFile)
    {

    }

    User enterUserData();
    void userRegister();
    void showUserData(User user);
    void showAllUsers();
    void loginUser();
    void loadUsers();
    void changeUserPassword();
};

#endif // header guard

