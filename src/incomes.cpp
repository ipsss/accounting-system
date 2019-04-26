#ifndef __INCOMES_CPP__
#define __INCOMES_CPP__
#include "incomes.h"
#include "account.h"
#include "account.cpp"
using namespace std;


vector<ACCOUNT> INCOMES::getincome() {return Incomes;}
unsigned int INCOMES::getIndex() {return index;}

void INCOMES::SearchIncomes(vector<ACCOUNT> Incomes){
  unsigned int index;  int search_date,search_month,search_year; double search_amount;
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
  cout << "Enter the kind of account for the Income: "<< endl;
  getline(cin,search_account);
  for (int i=0; i < Incomes.size(); i++) {
    if (Incomes[i].getdate()==search_date&&Incomes[i].getmonth()==search_month&&Incomes[i].getyear()==search_year&&Incomes[i].getamount()==search_amount&&Incomes[i].gettypes()==search_types&&Incomes[i].getaccount()==search_account)
      index=i;
    else {
      cout << "Result not found!" << endl;
    }
  }
}
void INCOMES::AddIncomes(ACCOUNT new_account){
  Incomes.push_back(new_account);
}

//BUGGED
void INCOMES::DeleteIncomes(Incomes,SearchIncomes(Incomes)){
  Incomes.erase(Incomes.begin()+index);
}

void INCOMES::EditIncomes(ACCOUNT new_account,unsigned int index){
  Incomes[index]=new_account;
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

void SortIncomes(vector<ACCOUNT> &Incomes){
  sort(Incomes.begin(),Incomes.end(),compare);
}


void INCOMES::ReadFromIncomes(vector<ACCOUNT> Incomes) {
  for (int i = 0; i < Incomes.size(); i++) {
    cout << Incomes[i].getrecord() << endl;
    cout << "Date: " << Incomes[i].getdate() << endl;
    cout << "Month: " << Incomes[i].getmonth() << endl;
    cout << "Year: " << Incomes[i].getyear() << endl;
    cout << "Ammount: " << fixed << setprecision(5) << Incomes[i].getamount() << endl;
    cout << "Types of Income: " << Incomes[i].gettypes() << endl;
    cout << "The kind of account for the Income: " << Incomes[i].getaccount() << endl;
    cout << endl;
  }
}
void INCOMES::WriteToIncomes(vector<ACCOUNT> Incomes) {
  ofstream fout("userID_Incomes.txt");
  if (!fout){
    cout << "Cannot open text file!" << endl;
  }
    for (int i = 0; i < Incomes.size(); i++) {
    fout << Incomes[i].getrecord() << endl;
    fout << "Date: " << Incomes[i].getdate() << endl;
    fout << "Month: " << Incomes[i].getmonth() << endl;
    fout << "Year: " << Incomes[i].getyear() << endl;
    fout << "Ammount: " << fixed << setprecision(5) << Incomes[i].getamount() << endl;
    fout << "Types of Income: " << Incomes[i].gettypes() << endl;
    fout << "The kind of account for the Income: " << Incomes[i].getaccount() << endl;
    fout << endl;
  }
  fout.close();
}

#endif
