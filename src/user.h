#ifndef __USER_H__
#define __USER_H__
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//This is a class for user to create their own account, each user could create one account only
class USER {
  public:

    USER(string id,string password); //default constructor

    //Accessor function
    string getUserId();
    string getUserPassword();

    //Mutator function
    //user could create new user account and set their id and password
    void setUserId(string new_id);
    void setUserPassword(string new_password);

    //Function: To check user want to check password or not
    //return true if user want to change password, return false if not
    bool changePassword(string YN);

    //Function: File Input of the changed id and password of the user
    void WritePassword(string id,string password);

    //Function: To test rather the input id and password is correct or not
    //return true when input coorect, return false when input is wrong
    bool Verification(string id,string password);

  private:
    string user_id;        //user id
    string user_password;  //user password
};

#endif
