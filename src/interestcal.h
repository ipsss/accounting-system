#ifndef __INTERESTCAL_H__
#define __INTERESTCAL_H__
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;

class SINTERESTCAL {
  public:
    //Constructor of simple interest account
    SINTERESTCAL(string bank_no,double principal,double interest_rate,int duration,string time);

    //Accessor function
    string getBank_no();
    double getPrincipal();
    double getInterestRate();
    double getDuration();
    double getInterest();
    double getTotalAmount();
    string getTime();

    //Mutator function
    void setBank_no(string new_bank_no);
    void setPrincipal(double new_principal);
    void setInterestRate(double new_interest_rate);
    void setDuration(double new_duration);
    void setInterest(double new_interest);
    void setTotalAmount(double new_total_amount);
    void setTime(string new_time);

    //Function: User could choose the duration of deposit period
    void Durationselection(string time);

    //Function: To find simple interest of the input interest rate, principal and the deposit duration
    double FindInterest(double principal,double interest_rate,double deposit_duration);

    //Function: File Output. Report file of the results
    void WriteInterest(string username);

  private:
    string bank_no;
    double principal;
    double interest_rate;
    double deposit_duration;
    string time;
    double interest;
    double Total_Amount;
};

#endif
