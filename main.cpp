#include <iostream>

#include "UserManager.h"
#include "BudgetManager.h"
#include "AuxilaryMethods.h"

using namespace std;

int main()
{
    BudgetManager budgetManager(1,"Incomes.xml");
    UserManager userManager("Users.xml");
    budgetManager.addOperation(INCOME);
}
