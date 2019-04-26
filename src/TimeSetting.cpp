#include "Timesetting.h"
#ifndef __TIMESETTING_CPP__
#define __TIMESETTING_CPP__

//Function: To test input date within normal range or not
bool DateRange(int new_date,int new_month,int new_year) {
  switch (new_month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
      if (new_date<=0 || new_date>31) {
        cout << "Date should be smaller than 32 or larger than 0" << endl;
        return false;
      }
      else
        return true;
      break;
    case 4: case 6: case 9: case 11:
      if (new_date<=0 || new_date>30) {
        cout << "Date should be smaller than 31 or larger than 0" << endl;
        return false;
      }
      else
        return true;
      break;
    case 2:
      if (new_date<=0 || new_date>28) {
        if ((new_year%4==0) && (new_year%100!=0 || new_year%400==0) && (new_date==29))
          return true;
        else {
          cout << "Date should be smaller than 29 unless it is a leap year or it should be larger than 0 " << endl;
          return false;
        }
      }
      else
        return true;
      break;
  }
}
//Function: To test input month within normal range or not
bool MonthRange(int new_month) {
  if (new_month<=0 || new_month>12) {
    cout << "The value of month should be in range 1-12 only" << endl;
    return false;
  }
  else
    return true;
}
//Function: To test input year within normal range or not
bool YearRange(int new_year) {
  if (new_year>2019) {
    cout << new_year << " not come yet." << endl;
    return false;
  }
  else
    return true;
}

#endif
