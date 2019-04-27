#ifndef __EXPENSES_H__
#define __EXPENSES_H__
#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "account.h"
#include "account.cpp"
using namespace std;

class EXPENSES {
  public:
    unsigned int index;
    
    //Accessor
    vector<ACCOUNT> getExpenses();
    unsigned int getIndex();
    
    //Mutator
    void setExpenses(vector<ACCOUNT>);
    void setIndex(unsigned int);

    bool SearchExpenses(vector<ACCOUNT>);  //Searching corresponding expense record
    void AddExpenses(ACCOUNT new_account); //Add expense record
    void DeleteExpenses(unsigned int);     //Delete the corresponding expense record
    void EditExpenses(ACCOUNT new_account,unsigned int);  //Edit corresponding expense record

    vector<ACCOUNT> SortExpenses(vector<ACCOUNT>); //Sort the expense records vector
    bool compare(ACCOUNT left,ACCOUNT right);      //compare two expense records
    void ReadFromExpenses(vector <ACCOUNT>);       //Show expense records
  
    //File Output. File storing all expense records from the user
    //This function would create (update) the file called "(userid)_Expenses.txt"
    void WriteToFile(string username,vector<ACCOUNT> Expenses);
    
    //Function: Find the total amount of expense
    double TotalExpense(vector<ACCOUNT>);
  
  private:
    vector<ACCOUNT> Expenses;
};

#endif
