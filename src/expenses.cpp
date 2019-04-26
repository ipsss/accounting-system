#include "expenses.h"
#ifndef __EXPENSES_CPP__
#define __EXPENSES_CPP__
#include<iostream>
using namespace std;

//Accessor
vector<ACCOUNT> EXPENSES::getExpenses() {return Expenses;}
unsigned int EXPENSES::getIndex() {return index;}

//Function: Search corresponding Expense Reocrd and find its index in the vector of Expense Records
void EXPENSES::SearchExpenses(vector<ACCOUNT> Expenses){
  unsigned int new_index; int search_date,search_month,search_year; double search_amount;
  string search_types,search_account;
  cout << "Enter the date: " << endl;
  cin >> search_date;
  cout << "Enter the mounth: " << endl;
  cin >> search_month;
  cout << "Enter the year: "<< endl;
  cin >> search_year;
  cout << "Enter the amount: "<< endl;
  cin >> search_amount;
  cout << "Enter the type: "<< endl;
  cin.ignore();
  getline(cin,search_types);
  cout << "Enter the kind of account for the Expense: "<< endl;
  getline(cin,search_account);
  for (int i=0; i < Expenses.size(); i++) {
    if (Expenses[i].getdate()==search_date&&Expenses[i].getmonth()==search_month&&Expenses[i].getyear()==search_year&&Expenses[i].getamount()==search_amount&&Expenses[i].gettypes()==search_types&&Expenses[i].getaccount()==search_account)
      index=new_index;
    else {
      cout << "Result not found!" << endl;
    }
  }
}
//Function: Add single Expense Record to the vector of Expense Records
void EXPENSES::AddExpenses(ACCOUNT new_account){
  Expenses.push_back(new_account);
}
//Function: Delete a target Expense Record from the vector of Expense Records
void EXPENSES::DeleteExpenses(unsigned int index){
  Expenses.erase(Expenses.begin()+index);
}
//Function: Change the target Expense Record in the vector of Expense Records 
void EXPENSES::EditExpenses(ACCOUNT new_account,unsigned int index){
  Expenses[index]=new_account;
}

//void EXPENSES::SortExpenses(vector<ACCOUNT>) {}

//Function: Read all the inputted Expenses Records
void EXPENSES::ReadFromExpenses(vector<ACCOUNT> Expenses) {
  for (int i = 0; i < Expenses.size(); i++) {
    cout << Expenses[i].getrecord() << endl;
    cout << "Date: " << Expenses[i].getdate() << endl;
    cout << "Month: " << Expenses[i].getmonth() << endl;
    cout << "Year: " << Expenses[i].getyear() << endl;
    cout << "Amount: " << fixed << setprecision(2) << Expenses[i].getamount() << endl;
    cout << "Types of Expense: " << Expenses[i].gettypes() << endl;
    cout << "The kind of account for the Expense: " << Expenses[i].getaccount() << endl;
    cout << endl;
  }
}
//void EXPENSES::WriteToExpenses() {}

#endif
