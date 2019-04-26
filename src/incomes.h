#ifndef __INCOMES_H__
#define __INCOMES_H__
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iomanip>

class INCOMES {
  public:
  
    unsigned int index;
  
    INCOMES(); //default constructor
    vector<ACCOUNT> getincome();
    unsigned int getIndex();
  
    void SearchIncomes(vector<ACCOUNT>);
    void AddIncomes(ACCOUNT new_account);
    void DeleteIncomes(vector<ACCOUNT>,unsigned int);
    void EditIncomes(ACCOUNT new_account,unsigned int);
    void SortIncomes(vector<ACCOUNT>);
    void ReadFromIncomes(vector <ACCOUNT>);
    void WriteToIncomes(vector<ACCOUNT> Incomes);
  
  private:
    vector<ACCOUNT> Incomes;
};

#endif
