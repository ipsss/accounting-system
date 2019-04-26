#include "user.h"
#include "user.cpp"
#include "incomes.h"
#include "incomes.cpp"
#include "Expenses.h"
#include "Expenses.cpp"
#include "Timesetting.h"
#include "Timesetting.cpp"
#include "BudgetSetting.h"
#include "BudgetSetting.cpp"
#include <iomanip>

int main() {
  string temp1,id,password,commend,record,types,account;
  int date,month,year,num;
  double amount,Total_Expense;
  cout << "Welcome to this accounting system." << endl;
  cout << "Have you create your account?" << endl;
  cin >> temp1;
  if (temp1=="Yes") {
    cout << "Please Login" << endl;
    cout << "Enter your user-id:";
    cin >> id;
    cout << "Enter your password:";
    cin >> password;
    USER u1(id,password);
    if (!u1.Verification(id,password)) {
      cout << "Action fail!" << endl;
      cout << "Incorrect user-id or password!!" << endl;
      cout << "Please restart and try again!" << endl;
      exit(1);
    }
    else
      cout << "Welcome!" << endl;
  }
  else if (temp1=="No") {
    cout << "Please create your account." << endl;
    cout << "Enter your user-id:";
    cin >> id;
    cout << "Enter your password:";
    cin >> password;
    USER u1(id,password);
    u1.WritePassword(id,password);
    cout << "Your account have been created" << endl;
  }
  else {
    cout << "'Yes' or 'No' only" <<endl;
    cout << "Please restart again" <<endl;
    exit(1);
  }
  USER u1(id,password);
  INCOMES MyIncomes;
  EXPENSES MyExpenses;
  cout << "What do you want to do?" << endl;
  getline(cin,commend);
  while (commend!="Logout") {
    if (commend=="change password") {
      cout << "Do you really want to change password?" <<endl;
      cin >> temp1;
      if (u1.changePassword(temp1)) {
        cout << "Enter your user-id:";
        cin >> id;
        cout << "Enter your old password:";
        cin >> password;
        if (u1.Verification(id,password)) {
          cout << "Now change your password" << endl;
          cout << "Enter your new password:";
          cin >> password;
          u1.WritePassword(id,password);
          cout << "Your password is sucessfully changed!" << endl;
        }
        else {
          cout << "Action fail!" << endl;
          cout << "Incorrect user-id or password!!" << endl;
          cout << "Please restart and try again!" << endl;
          exit(1);
        }
      }
    }
    else if (commend=="Add Income") {
      cout << "How many incomes you want to add?" << endl;
      cin >> num;
      while (num <= 0) {
        cout << "The input value should be a interger and larger than zero" << endl;
        cout << "Please input the value again" << endl;
        cout << "How many incomes you want to add?" << endl;
        cin >> num;
      }
      cout << "Please enter the following details" << endl;
      for (int i = 0; i < num; i++) {
        record="Income";
        cout << "Enter the year" << endl;
        cin >> year;
        while (!YearRange(year)) {
          cout << "Re-enter the year" << endl;
          cin >> year;
        }
        cout << "Enter the month" << endl;
        cin >> month;
        while (!MonthRange(month)) {
          cout << "Re-enter the month" << endl;
          cin >> month;
        }
        cout << "Enter the date" << endl;
        cin >> date;
        while (!DateRange(date,month,year)) {
          cout << "Re-enter the date" << endl;
          cin >> date;
        }
        cout << "Enter the amount" << endl;
        cin >> amount;
        cout << "Enter the type of income, like selling goods,salary,etc." << endl;
        cin.ignore();
        getline(cin,types);
        cout << "Enter the kind of account for the income, like cash,bank card account,etc." << endl;
        getline(cin,account);
        ACCOUNT MyAccount(record,date,month,year,amount,types,account);
        MyIncomes.AddIncomes(MyAccount);
      }
    }
    else if (commend=="Read Income Records")
      MyIncomes.ReadFromIncomes(MyIncomes.getIncome());

    else if (commend=="Add Expense") {
      cout << "How many expenses you want to add?" << endl;
      cin >> num;
      while (num <= 0) {
        cout << "The input value should be a interger and larger than zero" << endl;
        cout << "Please input the value again" << endl;
        cout << "How many expenses you want to add?" << endl;
        cin >> num;
      }
      cout << "Please enter the following details" << endl;
      for (int i = 0; i < num; i++) {
        record="Expense";
        cout << "Enter the year" << endl;
        cin >> year;
        while (!YearRange(year)) {
          cout << "Re-enter the year" << endl;
          cin >> year;
        }
        cout << "Enter the month" << endl;
        cin >> month;
        while (!MonthRange(month)) {
          cout << "Re-enter the month" << endl;
          cin >> month;
        }
        cout << "Enter the date" << endl;
        cin >> date;
        while (!DateRange(date,month,year)) {
          cout << "Re-enter the date" << endl;
          cin >> date;
        }
        cout << "Enter the amount" << endl;
        cin >> amount;
        cout << "Enter the type of expense, like buying food,buying games,etc." << endl;
        cin.ignore();
        getline(cin,types);
        cout << "Enter the kind of account for the expense, like cash,bank card account,credit card,etc." << endl;
        getline(cin,account);
        ACCOUNT MyAccount(record,date,month,year,amount,types,account);
        MyExpenses.AddExpenses(MyAccount);
      }
    }
    else if (commend=="Read Expense Records")
      MyExpenses.ReadFromExpenses(MyExpenses.getExpenses());

    else if (commend=="Budget Setting") {
      cout << "Set your Budget Amount: ";
      cin >> new_budget_setting;
      SetBudget(budget_setting,new_budget_setting);
      BudgetAlert(budget_setting,Total_Expense);
    }

    cout << "What do you want to do?" << endl;
    getline(cin,commend);
  }
  return 0;
}
