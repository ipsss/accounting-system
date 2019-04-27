#ifndef __BUDGETSETTING_H__
#define __BUDGETSETTING_H__

double budget_setting=100000; //default budget setting is $100000 (upper limit)
double new_budget_setting;
extern double SetBudget(double&,double&); //Function: Set Budget
extern void BudgetAlert(double,double); //Function: Output alert when Expenses exceed the Budget setting

#endif
