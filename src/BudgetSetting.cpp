#ifndef __BUDGETSETTING_CPP__
#define __BUDGETSETTING_CPP__

//Function: For user to set their own budget
double SetBudget(double &budget_setting,double &new_budget_setting) {
  budget_setting=new_budget_setting;
}
//Function: Output alert when Expenses exceed the Budget setting
void BudgetAlert(double budget_setting, double Total_Expense) {
  if (Total_Expense > budget_setting) {
    cout << "Your budget_setting is: " << budget_setting <<endl;
    cout << "Your Total_Expense is: " << Total_Expense << endl;
    cout << "Your Total_Expense is larger than your budget_setting!!!" << endl;
  }
}
#endif
