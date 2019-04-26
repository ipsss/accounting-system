#ifndef __USER_CPP__
#define __USER_CPP__
using namespace std;

//default constructor
USER::USER(string id,string password) {
  setUserId(id);
  setUserPassword(password);
}

//Accessor function
string USER::getUserId() {return user_id;}
string USER::getUserPassword() {return user_password;}

//Mutator function
void USER::setUserId(string new_id) {
  user_id=new_id;
}
void USER::setUserPassword(string new_password) {
  user_password=new_password;
}

//Function: To check user want to check password or not
//return true if user want to change password, return false if not
bool USER::changePassword(string YN) {
  if (YN=="Yes")
    return true;
  else
    return false;
}

//Function: File Input of the changed id and password of the user
void USER::WritePassword(string username,string password) {
  ofstream file1;
  file1.open((username+".txt").c_str());
  if (file1.fail()) {
    cout << "Sorry, something goes wrong!" << endl;
    cout << "Please restart again..." << endl;
    exit(1);
  }
  setUserPassword(password);
  file1 << password << endl;
  file1.close();
}

//Function: To test rather the input id and password is correct or not
//return true when input coorect, return false when input is wrong
bool USER::Verification(string username,string password) {
  bool ok;
  ifstream file1;
  string str1;
  file1.open((username+".txt").c_str());
  if (file1.fail()) {
    cout << "Action fail!" << endl;
    cout << "Incorrect user-id or password!!" << endl;
    cout << "Please restart and try again!" << endl;
    exit(1);
  }
  file1 >> str1;
  if (str1==password)
    ok=1;
  else
    ok=0;
  file1.close();
  return ok;
}

#endif
