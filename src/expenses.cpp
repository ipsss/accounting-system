#include "expenses.h"
#ifndef __EXPENSES_CPP__
#define __EXPENSES_CPP__
#include<iostream>
using namespace std;

//Accessor
vector<ACCOUNT> EXPENSES::getExpenses() {return Expenses;}
unsigned int EXPENSES::getIndex() {return index;}

//Mutator
void EXPENSES::setExpenses(vector<ACCOUNT> new_Expenses) {
  Expenses=new_Expenses;
}
void EXPENSES::setIndex(unsigned int new_index) {
  index=new_index;
}

//Function: Search corresponding expense reocrd and find its index in the vector of Expense Records
bool EXPENSES::SearchExpenses(vector<ACCOUNT> Expenses){
  int search_date,search_month,search_year; double search_amount;
  string search_types,search_account;
  index=0;
  cout << "Enter the date: " << endl;
  cin >> search_date;
  cout << "Enter the month: " << endl;
  cin >> search_month;
  cout << "Enter the year: "<< endl;
  cin >> search_year;
  cout << "Enter the amount: "<< endl;
  cin >> search_amount;
  cout << "Enter the type: "<< endl;
  cin.ignore();
  getline(cin,search_types);
  cout << "Enter the kind of account for the Income: "<< endl;
  getline(cin,search_account);
  for (int i=0; i < Expenses.size(); i++) {
    if (Expenses[i].getdate()==search_date&&Expenses[i].getmonth()==search_month&&Expenses[i].getyear()==search_year&&Expenses[i].getamount()==search_amount&&Expenses[i].gettypes()==search_types&&Expenses[i].getaccount()==search_account)
    {
      setIndex(i);
      return true;
    }
  }
  return false;
}

//Function: Add single Expense Record to the vector of Expense Records
void EXPENSES::AddExpenses(ACCOUNT new_account){
  Expenses.push_back(new_account);
}
//Function: Delete a target Expense Record from the vector of Expense Records
void EXPENSES::DeleteExpenses(unsigned int index){
  Expenses.erase(Expenses.begin()+index);
  cout << "The corresponding expense record is deleted." << endl;
}
//Function: Change the target Expense Record in the vector of Expense Records
void EXPENSES::EditExpenses(ACCOUNT new_account,unsigned int index){
  Expenses[index]=new_account;
  cout << "The corresponding expense record is sucessfully changed." << endl;
}

//Function: Compare two expense records
bool EXPENSES::compare(ACCOUNT left,ACCOUNT right){
  if (left.getyear() > right.getyear()){
    return true;
  }
  else if (left.getyear() == right.getyear() && left.getmonth() > right.getmonth()){
    return true;
  }
  else if (left.getyear() == right.getyear() && left.getmonth() == right.getmonth() && left.getdate() > right.getdate()){
    return true;
  }
  else if (left.getyear() == right.getyear() && left.getmonth() == right.getmonth() && left.getdate()== right.getdate() && left.getamount() > right.getamount()) {
    return true;
  }
  else
    return false;
}
//Function: Sort the expense records vector
vector<ACCOUNT> EXPENSES::SortExpenses(vector<ACCOUNT> Expenses){
  for (int i = Expenses.size()-1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      if (compare(Expenses[j],Expenses[j+1])){
        swap(Expenses[j],Expenses[j+1]);
      }
    }
  }
  return Expenses;
}

//Function: Show all expense records in the expense records vector
void EXPENSES::ReadFromExpenses(vector<ACCOUNT> Expenses) {
  for (int i = 0; i < Expenses.size(); i++) {
    cout << Expenses[i].getrecord() << endl;
    cout << "Date: " << Expenses[i].getdate() << endl;
    cout << "Month: " << Expenses[i].getmonth() << endl;
    cout << "Year: " << Expenses[i].getyear() << endl;
    cout << "Amount: " <<Expenses[i].getamount() << endl;
    cout << "Types of Expense: " << Expenses[i].gettypes() << endl;
    cout << "The kind of account for the Expense: " << Expenses[i].getaccount() << endl;
    cout << endl;
  }
}

//Function: File Output. File storing all expense records from the user
//This function would create (update) the file called "(userid)_Expenses.txt"
void EXPENSES::WriteToFile(string username,vector<ACCOUNT> Expenses) {
  ofstream fout((username+"_Expenses.txt").c_str());
  if (!fout){
    cout << "Sorry, something goes wrong..." << endl;
    cout << "Cannot open text file!" << endl;
    exit(1);
  }
    for (int i = 0; i < Expenses.size(); i++) {
      fout << "New " << Expenses[i].getrecord() << endl;
      fout << "Date: " << Expenses[i].getdate() << endl;
      fout << "Month: " << Expenses[i].getmonth() << endl;
      fout << "Year: " << Expenses[i].getyear() << endl;
      fout << "Amount: " << fixed << setprecision(2) << Expenses[i].getamount() << endl;
      fout << "Types of Expense: " << Expenses[i].gettypes() << endl;
      fout << "The kind of account for the Expense: " << Expenses[i].getaccount() << endl;
      fout << endl;
  }
  fout.close();
}

//Function: Find the total amount of expense
double TotalExpense(vector<ACCOUNT> Expenses){
  double Total=0;
  for (int i=0;i<Expenses.size();i++){
    Total+=Expenses[i].getamount()
  }
  return Total;
}

#endif
