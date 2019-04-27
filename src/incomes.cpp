#include "incomes.h"
#ifndef __INCOMES_CPP__
#define __INCOMES_CPP__

//Accessor
vector<ACCOUNT> INCOMES::getIncome() {return Incomes;}
unsigned int INCOMES::getIndex() {return index;}

//Mutator
void INCOMES::setIncome(vector<ACCOUNT> new_Incomes) {
  Incomes=new_Incomes;
}
void INCOMES::setIndex(unsigned int new_Index) {
  index=new_Index;
}

//Searching corresponding income record
bool INCOMES::SearchIncomes(vector<ACCOUNT> Incomes){
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
  for (int i=0; i < Incomes.size(); i++) {
    if (Incomes[i].getdate()==search_date&&Incomes[i].getmonth()==search_month&&Incomes[i].getyear()==search_year&&Incomes[i].getamount()==search_amount&&Incomes[i].gettypes()==search_types&&Incomes[i].getaccount()==search_account)
    {
      setIndex(i);
      return true;
    }
  }
  return false;
}

//Add income record
void INCOMES::AddIncomes(ACCOUNT new_account){
  Incomes.push_back(new_account);
}

//Delete the corresponding income record
void INCOMES::DeleteIncomes(unsigned int index){
  Incomes.erase(Incomes.begin()+index);
  cout << "The corresponding income record is deleted." << endl;
}

//Edit corresponding income record
void INCOMES::EditIncomes(ACCOUNT new_account,unsigned int index){
  Incomes[index]=new_account;
  cout << "The corresponding income record is sucessfully changed." << endl;
}

//Compare two income records
bool INCOMES::compare(ACCOUNT left,ACCOUNT right){
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

//Sort the income records vector
vector<ACCOUNT> INCOMES::SortIncomes(vector<ACCOUNT> Incomes){
  for (int i = Incomes.size()-1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      if (compare(Incomes[j],Incomes[j+1])){
        swap(Incomes[j],Incomes[j+1]);
      }
    }
  }
  return Incomes;
}

//Show Income records
void INCOMES::ReadFromIncomes(vector<ACCOUNT> Incomes) {
  for (int i = 0; i < Incomes.size(); i++) {
    cout << Incomes[i].getrecord() << endl;
    cout << "Date: " << Incomes[i].getdate() << endl;
    cout << "Month: " << Incomes[i].getmonth() << endl;
    cout << "Year: " << Incomes[i].getyear() << endl;
    cout << "Amount: " << Incomes[i].getamount() << endl;
    cout << "Types of Income: " << Incomes[i].gettypes() << endl;
    cout << "The kind of account for the Income: " << Incomes[i].getaccount() << endl;
    cout << endl;
  }
}

//File Output. File storing all income records from the user
//This function would create (update) the file called "(userid)_Incomes.txt"
void INCOMES::WriteToFile(string username,vector<ACCOUNT> Incomes) {
  ofstream fout((username+"_Incomes.txt").c_str());
  if (!fout){
    cout << "Sorry, something goes wrong..." << endl;
    cout << "Cannot open text file!" << endl;
    exit(1);
  }
  for (int i = 0; i < Incomes.size(); i++) {
    fout << "New " << Incomes[i].getrecord() << endl;
    fout << "Date: " << Incomes[i].getdate() << endl;
    fout << "Month: " << Incomes[i].getmonth() << endl;
    fout << "Year: " << Incomes[i].getyear() << endl;
    fout << "Amount: " << fixed << setprecision(2) << Incomes[i].getamount() << endl;
    fout << "Types of Income: " << Incomes[i].gettypes() << endl;
    fout << "The kind of account for the Income: " << Incomes[i].getaccount() << endl;
    fout << endl;
  }
  fout.close();
}

//Calculate total amount of income
double INCOMES::TotalIncome(vector<ACCOUNT> Incomes){
  double Total=0;
  for (int i=0;i<Incomes.size();i++){
    Total+=Incomes[i].getamount();
  }
  return Total;
}

#endif
