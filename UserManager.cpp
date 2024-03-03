#include "UserManager.h"

using namespace std;

User UserManager::enterUserData()
{
    User user;

    cout << "Registering new user" << endl << "--- --- --- ---" << endl;
    user.id = (fileWithUsers.getLastUserId() + 1);
    cout << "Type user's first name: ";
    user.firstName = AuxilaryMethods::readLine();
    cout << "Type user's last name: ";
    user.lastName = AuxilaryMethods::readLine();
    cout << "Type user's login: ";
    user.login = AuxilaryMethods::readLine();
    cout << "Type user's password: ";
    user.password = AuxilaryMethods::readLine();

    return user;
}

void UserManager::userRegister()
{
    User userToAdd = enterUserData();
    users.push_back(userToAdd);
    fileWithUsers.addUserToFile(userToAdd);
}

void UserManager::showUserData(User user)
{
    cout << "First name: " << user.firstName << endl;
    cout << "Last name: " << user.lastName << endl;
    cout << "Login: " << user.login << endl;
}

void UserManager::showAllUsers()
{
    for (size_t i = 0; i < users.size(); i++)
    {
        showUserData(users[i]);
    }
}

void UserManager::loginUser()
{
    cout << "Type user's login: ";
    string login = AuxilaryMethods::readLine();
    string passwordToCheck = "";
    int idToGet;

    for (size_t i = 0; i < users.size(); i++)
    {
        if (login == users[i].login)
        {
            passwordToCheck = users[i].password;
            idToGet = users[i].id;
            break;
        }
    }

    if (passwordToCheck.empty())
    {
        cout << "No user with that login found!";
        exit(0);
    }

    string password;

    for (int i = 0; i < 3; i++)
    {
        cout << "Type user's password - you have " << 3 - i << " trials: ";

        password = AuxilaryMethods::readLine();

        if (password == passwordToCheck)
        {
            cout << "User successfully logged in" << endl;
            loggedUserId = idToGet;
            return;
        }

        if (i == 2)
        {
            cout << "Too many atempts to log in. Access denied" << endl;
        }
    }
}

void UserManager::loadUsers()
{
    users = fileWithUsers.loadUsersFromFile();
}

void UserManager::changeUserPassword()
{
    User userToUpdate;
    cout << "Type new password: ";

    string newPassword;

    newPassword = AuxilaryMethods::readLine();

    for (size_t i = 0; i < users.size(); i++)
    {
        if (loggedUserId == users[i].id)
        {
            users[i].password = newPassword;

            userToUpdate.id = users[i].id;
            userToUpdate.firstName = users[i].firstName;
            userToUpdate.lastName = users[i].lastName;
            userToUpdate.login = users[i].login;
            userToUpdate.password = users[i].password;

            fileWithUsers.updatingUserData(userToUpdate);

            cout << "Your password has been changed" << endl;

            break;
        }
    }

    return;
}
