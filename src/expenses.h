#ifndef __EXPENSES_H__
#define __EXPENSES_H__
#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <iomanip>
#include "account.h"
#include "account.cpp"
using namespace std;

class EXPENSES {
  public:
    unsigned int index;

    vector<ACCOUNT> getExpenses();
    unsigned int getIndex();

    void SearchExpenses(vector<ACCOUNT>);
    void AddExpenses(ACCOUNT new_account);
    void DeleteExpenses(unsigned int);
    void EditExpenses(ACCOUNT new_account,unsigned int);
    bool compare(ACCOUNT, ACCOUNT);
    void SortExpenses(vector<ACCOUNT>);
    void ReadFromExpenses(vector <ACCOUNT>);
    void WriteToExpenses(vector<ACCOUNT>,string);
    double TotalExpense(vector<ACCOUNT>)

  private:
    vector<ACCOUNT> Expenses;
};

#endif
