#ifndef __INTERESTCAL_H__
#define __INTERESTCAL_H__
#include <iostream>
#include <cmath>
using namespace std;

class SINTERESTCAL {
  public:
    string time;
    SINTERESTCAL(string bank_no);  //default constructor of simple interest account
  
    //Accessor function
    string getBank_no();
    double getInterestRate();
    double getPrincipal();
    int getDuration();
  
    //Mutator function
    void setBank_no(string bank_no);
    void setInterestRate(double new_interest_rate);
    void setPrincipal(double new_principal);
    void setDuration(double new_duration);
    
    //Function: User could choose the duration of deposit period
    void Durationselection(string time);
  
    //Function: To find simple interest of the input rate, principal and the deposit duration
    double FindInterest(double interest_rate,double principal,int deposit_duration);
  
    //Function: File Output of the simple interest
    void WriteInterest(double interest);
  
  private:
    const string bank_no;
    double interest_rate;
    double principal;
    double interest; 
    int deposit_duration;
};

#endif
