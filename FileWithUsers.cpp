#include "FileWithUsers.h"

using namespace std;

void FileWithUsers::addUserToFile(User user)
{
    CMarkup workingFile;

    if (!workingFile.Load(getFileName()))
    {
        workingFile.AddElem("Users");
        workingFile.IntoElem();
        workingFile.AddElem("User");
        workingFile.IntoElem();
        workingFile.AddElem("id",to_string(user.id));
        workingFile.AddElem("firstName",user.firstName);
        workingFile.AddElem("lastName",user.lastName);
        workingFile.AddElem("login",user.login);
        workingFile.AddElem("password",user.password);
        workingFile.OutOfElem();
        workingFile.OutOfElem();
        workingFile.Save(getFileName());
    }

    else
    {
        workingFile.FindElem("Users");
        workingFile.IntoElem();
        while(workingFile.FindElem("User"))
        {

        }
        workingFile.AddElem("User");
        workingFile.IntoElem();
        workingFile.AddElem("id",to_string(user.id));
        workingFile.AddElem("firstName",user.firstName);
        workingFile.AddElem("lastName",user.lastName);
        workingFile.AddElem("login",user.login);
        workingFile.AddElem("password",user.password);
        workingFile.OutOfElem();
        workingFile.OutOfElem();
        workingFile.Save(getFileName());
    }

    lastUserId++;
}

vector <User> FileWithUsers::loadUsersFromFile()
{
    CMarkup workingFile;
    MCD_STR strXML;

    User user;
    vector <User> users;

    workingFile.Load(getFileName());

    workingFile.FindElem("Users");
    workingFile.IntoElem();

    while(workingFile.FindElem("User"))
    {
        workingFile.IntoElem();
        workingFile.FindElem("id");
        strXML = workingFile.GetData();
        user.id = stoi(strXML);
        workingFile.FindElem("firstName");
        strXML = workingFile.GetData();
        user.firstName = strXML;
        workingFile.FindElem("lastName");
        strXML = workingFile.GetData();
        user.lastName = strXML;
        workingFile.FindElem("login");
        strXML = workingFile.GetData();
        user.login = strXML;
        workingFile.FindElem("password");
        strXML = workingFile.GetData();
        user.password = strXML;
        workingFile.OutOfElem();

        users.push_back(user);
        lastUserId++;
    }

    return users;
}

void FileWithUsers::updatingUserData(User userToUpdate)
{
    CMarkup workingFile;
    MCD_STR strXML;

    workingFile.Load(getFileName());

    workingFile.FindElem("Users");
    workingFile.IntoElem();

    while(workingFile.FindElem("User"))
    {
        workingFile.IntoElem();
        workingFile.FindElem("id");
        strXML = workingFile.GetData();

        if (to_string(userToUpdate.id) == strXML)
        {
            workingFile.FindElem("firstName");
            workingFile.SetData(userToUpdate.firstName);
            workingFile.FindElem("lastName");
            workingFile.SetData(userToUpdate.lastName);
            workingFile.FindElem("login");
            workingFile.SetData(userToUpdate.login);
            workingFile.FindElem("password");
            workingFile.SetData(userToUpdate.password);

            workingFile.Save(getFileName());

            break;
        }

        workingFile.OutOfElem();
    }
}

int FileWithUsers::getLastUserId()
{
    return lastUserId;
}
