#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include <iostream>
#include <cstring>
using namespace std;

class ACCOUNT {
  public:

    ACCOUNT(string record,int date,int month,int year,double amount,string types,string account); //default constructor

    string getrecord();
    int getdate();
    int getmonth();
    int getyear();
    double getamount();
    string gettypes();
    string getaccount();

    void setrecord(string new_record);
    void setdate(int new_date);
    void setmonth(int new_month);
    void setyear(int new_year);
    void setamount(double new_amount);
    void settypes(string new_types);
    void setaccount(string new_account);

 private:
  string record;
  int date;
  int month;
  int year;
  double amount;
  string types;
  string account;
};

#endif
