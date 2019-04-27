#include "user.h"
#include "user.cpp"
#include "incomes.h"
#include "incomes.cpp"
#include "Expenses.h"
#include "Expenses.cpp"
#include "Timesetting.h"
#include "Timesetting.cpp"
#include "Interestcal.h"
#include "Interestcal.cpp"
#include "BudgetSetting.h"
#include "BudgetSetting.cpp"
#include <iomanip>

int main() {
  string temp1,id,password,commend,record,types,account,bank_no,time;
  int date,month,year,num,duration;
  double amount,principal,interest_rate;
  double Total_Expense=0.0;
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
  cout << "-----------------------------------------------------------------------------------------------" <<endl;
  cout << "You can do the following options: " << endl;
  cout << "Input \"Logout\" to Exit program" << endl;
  cout << "Input \"Add Income\" to add records of income" << endl;
  cout << "Input \"Add Expense\" to add records of expense" << endl;
  cout << "Input \"Delete Income\" or \"Edit Income\" to delete or edit personal income records" << endl;
  cout << "Input \"Delete Expense\" or \"Edit Expense\" to delete or edit personal expense records" << endl;
  cout << "Input \"Budget Setting\" to set budget" << endl;
  cout << "Input \"Use Interest Calculator\" to use simple interest calculator" << endl;
  cout << "Input \"Read Income Records\" to access your income records" << endl;
  cout << "Input \"Read Expense Records\" to access your expense records" << endl;
  cout << "-----------------------------------------------------------------------------------------------" <<endl;
  cout << endl;
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
      MyIncomes.setIncome(MyIncomes.SortIncomes(MyIncomes.getIncome()));
    }

    else if (commend=="Delete Income") {
      MyIncomes.setIncome(MyIncomes.SortIncomes(MyIncomes.getIncome()));
      MyIncomes.ReadFromIncomes(MyIncomes.getIncome());
      if (MyIncomes.SearchIncomes(MyIncomes.getIncome()))
        MyIncomes.DeleteIncomes(MyIncomes.getIndex());
      else
        cout << "Result not found!" << endl;
    }

    else if (commend=="Edit Income") {
      MyIncomes.setIncome(MyIncomes.SortIncomes(MyIncomes.getIncome()));
      MyIncomes.ReadFromIncomes(MyIncomes.getIncome());
      if (MyIncomes.SearchIncomes(MyIncomes.getIncome())) {
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
        MyIncomes.EditIncomes(MyAccount,MyIncomes.getIndex());
      }
      else
        cout << "Result not found!" << endl;
    }

    else if (commend=="Read Income Records") {
      MyIncomes.setIncome(MyIncomes.SortIncomes(MyIncomes.getIncome()));
      MyIncomes.ReadFromIncomes(MyIncomes.getIncome());
    }

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
      MyExpenses.setExpenses(MyExpenses.SortExpenses(MyExpenses.getExpenses()));
    }

    else if (commend=="Delete Expense") {
      MyExpenses.setExpenses(MyExpenses.SortExpenses(MyExpenses.getExpenses()));
      MyExpenses.ReadFromExpenses(MyExpenses.getExpenses());
      if (MyExpenses.SearchExpenses(MyExpenses.getExpenses()))
        MyExpenses.DeleteExpenses(MyExpenses.getIndex());
      else
        cout << "Result not found!" << endl;
    }

    else if (commend=="Edit Expense") {
      MyExpenses.setExpenses(MyExpenses.SortExpenses(MyExpenses.getExpenses()));
      MyExpenses.ReadFromExpenses(MyExpenses.getExpenses());
      if (MyExpenses.SearchExpenses(MyExpenses.getExpenses())) {
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
        cout << "Enter the type of income, like selling goods,salary,etc." << endl;
        cin.ignore();
        getline(cin,types);
        cout << "Enter the kind of account for the income, like cash,bank card account,etc." << endl;
        getline(cin,account);
        ACCOUNT MyAccount(record,date,month,year,amount,types,account);
        MyExpenses.EditExpenses(MyAccount,MyExpenses.getIndex());
      }
      else
        cout << "Result not found!" << endl;
    }

    else if (commend=="Read Expense Records") {
      MyExpenses.setExpenses(MyExpenses.SortExpenses(MyExpenses.getExpenses()));
      MyExpenses.ReadFromExpenses(MyExpenses.getExpenses());
    }

    else if (commend=="Budget Setting") {
      cout << "Set your Budget Amount: ";
      cin >> new_budget_setting;
      while (new_budget_setting>100000) {
        cout << "The maximum amount of budget should not be larger than $100000" << endl;
        cout << "Set your Budget Amount again: ";
        cin >> new_budget_setting;
      }
      SetBudget(budget_setting,new_budget_setting);
    }

    else if (commend=="Use Interest Calculator") {
      cout << "Please input our deposit account no.:" << endl;
      getline(cin,bank_no);
      cout << "Please input the principal (P):" << endl;
      cin >> principal;
      cout << "Please input the interest rate (r):" << endl;
      cin >> interest_rate;
      cout << "Please input the time length. You can choose year,half-year,quarter,month or day." << endl;
      cin >> time;
      cout << "Please input the deposit duration (t)" << endl;
      cout << "e.g. if you choose time length as year and your input is 5, the deposit duration would be 5 years."<< endl;
      cin >> duration;
      SINTERESTCAL MyInterest(bank_no,principal,interest_rate,duration,time);
      MyInterest.Durationselection(MyInterest.getTime());
      MyInterest.WriteInterest(id);
    }
    Total_Expense=MyExpenses.TotalExpense(MyExpenses.getExpenses());
    cout << "Your current total income and expense are " << MyIncomes.TotalIncome(MyIncomes.getIncome()) << " and " << MyExpenses.TotalExpense(MyExpenses.getExpenses()) << " respectively." << endl;
    BudgetAlert(budget_setting,Total_Expense);
    cout << "What do you want to do?" << endl;
    getline(cin,commend);
  }
  MyIncomes.WriteToFile(id,MyIncomes.getIncome());
  MyExpenses.WriteToFile(id,MyExpenses.getExpenses());
  cout << "You report is ready." << endl;
  return 0;
}
