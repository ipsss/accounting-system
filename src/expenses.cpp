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
      new_index=i;
    else {
      cout << "Result not found!" << endl;
    }
  }
  index=new_index;
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

bool compare(ACCOUNT left, ACCOUNT right){
  if (left.getyear() > right.getyear()){
    return true;
  }else if (left.getmonth() > right.getmonth()){
    return true;
  }else if (left.getdate() > right.getdate()){
    return true;
  }else if (left.getamount() > right.getamount()){
    return true;
  }else {
    return false;
  }
}

void EXPENSES::SortExpenses(vector<ACCOUNT> Expenses) {
sort(Expenses.begin(),Expenses.end(),compare);
}

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
void EXPENSES::WriteToExpenses(vector<ACCOUNT>Expenses,string userid) {
      ofstream fout((userid+"_Expenses.txt").c_str());
  if (!fout){
    cout << "Cannot open text file!" << endl;
  for (int i = 0; i < Expenses.size(); i++) {
    fout << Expenses[i].getrecord() << endl;
    fout << "Date: " << Expenses[i].getdate() << endl;
    fout << "Month: " << Expenses[i].getmonth() << endl;
    fout << "Year: " << Expenses[i].getyear() << endl;
    fout << "Amount: " << fixed << setprecision(2) << Expenses[i].getamount() << endl;
    fout << "Types of Expense: " << Expenses[i].gettypes() << endl;
    fout << "The kind of account for the Expense: " << Expenses[i].getaccount() << endl;
    fout << endl;
}
double TotalExpense(vector<ACCOUNT> Expenses){
  double Total=0;
  for (int i=0;i<Expenses.size();i++){
    Total+=Expenses[i].getamount()
  }
  return Total;
}

#endif
