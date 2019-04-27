#ifndef __INCOMES_H__
#define __INCOMES_H__
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iomanip>
#include "account.h"
#include "account.cpp"
using namespace std;

class INCOMES {
  public:

    unsigned int index;
    
    //Accessor
    vector<ACCOUNT> getIncome();
    unsigned int getIndex();
  
    //Mutator
    void setIncome(vector<ACCOUNT>);
    void setIndex(unsigned int);

    bool SearchIncomes(vector<ACCOUNT>);  //Searching ccorresponding income record
    void AddIncomes(ACCOUNT new_account); //Add income record
    void DeleteIncomes(unsigned int);     //Delete the corresponding income record
    void EditIncomes(ACCOUNT new_account,unsigned int); //Edit corresponding income record
  
    vector<ACCOUNT> SortIncomes(vector<ACCOUNT>);  //Sort the income records vector
    bool compare(ACCOUNT left,ACCOUNT right);      //compare two income records
    void ReadFromIncomes(vector <ACCOUNT>);        //Show Income records
  
    //File Output. File storing all income records from the user
    //This function would create (update) the file called "(userid)_Incomes.txt"
    void WriteToIncomes(vector<ACCOUNT>,string);

  private:
    vector<ACCOUNT> Incomes;
};

#endif
