#ifndef __ACCOUNT_CPP__
#define __ACCOUNT_CPP__

string ACCOUNT::getrecord() {return record;}
int ACCOUNT::getdate() {return date;}
int ACCOUNT::getmonth() {return month;}
int ACCOUNT::getyear() {return year;}
double ACCOUNT::getamount() {return amount;}
string ACCOUNT::gettypes() {return types;}
string ACCOUNT::getaccount() {return account;}

void ACCOUNT::setrecord(string new_record) {
  record=new_record;
}
void ACCOUNT::setdate(int new_date) {
  date=new_date;
}
void ACCOUNT::setmonth(int new_month) {
  month=new_month;
}
void ACCOUNT::setyear(int new_year) {
  year=new_year;
}
void ACCOUNT::setamount(double new_amount) {
  amount=new_amount;
}
void ACCOUNT::settypes(string new_types) {
  types=new_types;
}
void ACCOUNT::setaccount(string new_account) {
  account=new_account;
}

ACCOUNT::ACCOUNT(string record,int date,int month,int year,double amount,string types,string account) {
   setrecord(record);
   setdate(date);
   setmonth(month);
   setyear(year);
   setamount(amount);
   settypes(types);
   setaccount(account);
}

#endif
