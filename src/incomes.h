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

    INCOMES(); //default constructor
    vector<ACCOUNT> getIncome();
    unsigned int getIndex();

    void SearchIncomes(vector<ACCOUNT>);
    void AddIncomes(ACCOUNT new_account);
    void DeleteIncomes(vector<ACCOUNT>,unsigned int);
    void EditIncomes(ACCOUNT new_account,unsigned int);
    bool compare(ACCOUNT, ACCOUNT);
    void SortIncomes(vector<ACCOUNT>);
    void ReadFromIncomes(vector <ACCOUNT>);
    void WriteToIncomes(vector<ACCOUNT>,string);

  private:
    vector<ACCOUNT> Incomes;
};

#endif
