#ifndef __INTERESTCAL_CPP__
#define __INTERESTCAL_CPP__

//Accessor function
string SINTERESTCAL::getBank_no() {return bank_no;}
double SINTERESTCAL::getPrincipal() {return principal;}
double SINTERESTCAL::getInterestRate() {return interest_rate;}
double SINTERESTCAL::getDuration() {return deposit_duration;}
double SINTERESTCAL::getInterest() {return interest;}
double SINTERESTCAL::getTotalAmount() {return Total_Amount;}
string SINTERESTCAL::getTime() {return time;}

//Mutator function
void SINTERESTCAL::setBank_no(string new_bank_no) {
  bank_no=new_bank_no;
}
void SINTERESTCAL::setPrincipal(double new_principal) {
  principal=new_principal;
}
void SINTERESTCAL::setInterestRate(double new_interest_rate) {
  interest_rate=new_interest_rate;
}
void SINTERESTCAL::setDuration(double new_duration) {
  deposit_duration=new_duration;
}
void SINTERESTCAL::setInterest(double new_interest) {
  interest=new_interest;
}
void SINTERESTCAL::setTotalAmount(double new_total_amount) {
  Total_Amount=new_total_amount;
}
void SINTERESTCAL::setTime(string new_time) {
  time=new_time;
}

//Function: User could choose the duration of deposit period
//Choice: year, half-year, quarter, month, day
//This Function would call FindInterest() to calculate interest and total amount
void SINTERESTCAL::Durationselection(string time) {
  if (time=="year") {
    FindInterest(principal,(interest_rate/100),deposit_duration);
  }
  else if (time=="half-year") {
    FindInterest(principal,(interest_rate/100),(deposit_duration/2));
  }
  else if (time=="quarter") {
    FindInterest(principal,(interest_rate/100),(deposit_duration/4));
  }
  else if (time=="month") {
    FindInterest(principal,(interest_rate/100),(deposit_duration/12));
  }
  else if (time=="day") {
    FindInterest(principal,(interest_rate/100),(deposit_duration/365));
  }
}

//Function: To find simple interest from the input interest rate, principal and the deposit duration according to the user
double SINTERESTCAL::FindInterest(double principal,double interest_rate,double deposit_duration) {
  Total_Amount=principal*(1+interest_rate*deposit_duration);
  interest=Total_Amount-principal;
  cout << "The total amount(A) you have = $" << fixed << setprecision(2) << Total_Amount << endl;
  cout << "The interest(I) you get for your deposit account is $" << fixed << setprecision(2) << interest << endl;
}

//Function: File Output. Report file of the results
//This function would create a file called "(user_id)__interest_report.txt"
void SINTERESTCAL::WriteInterest(string username) {
  ofstream file1;
  file1.open((username+"_interest_report.txt").c_str());
  if (file1.fail()) {
    cout << "Sorry, something goes wrong!" << endl;
    cout << "Please restart again..." << endl;
    exit(1);
  }
  file1 << "Your deposit account no. is: " <<  bank_no << endl;
  file1 << "The principal(P) in your account is $" << fixed << setprecision(2) << principal << endl;
  file1 << "Interest rate(r) = " << interest_rate << "%" << endl;
  file1 << "The Deposite period(t) is " << deposit_duration << ' ' << time << endl;
  file1 << "The interest(I) you get for your deposit account = $" << fixed << setprecision(2) << interest << endl;
  file1 << "The total amount(A) you have = $" << fixed << setprecision(2) << Total_Amount << endl;
  file1.close();
}

//Constructor of a simple interest calculator object
SINTERESTCAL::SINTERESTCAL(string bank_no,double principal,double interest_rate,int duration,string time) {
  setBank_no(bank_no);
  setPrincipal(principal);
  setInterestRate(interest_rate);
  setDuration(duration);
  setTime(time);
  setInterest(0.0);
  setTotalAmount(0.0);
}

#endif
