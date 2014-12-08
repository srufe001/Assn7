//  =============== BEGIN ASSESSMENT HEADER ================
/// @file User.cpp
/// @brief assn4
///
/// @author Samuel Rufer [srufe001@ucr.edu]
/// @date November 12, 2014
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#include "User.h"
#include<string>

using namespace std;

User::User()
: username(), password()
{ }

User::User(const string& uname, const string& pass)
: username(uname), password(pass)
{ }

string User::get_username() const {
   return username;
}

bool User::check(const string& uname, const string& pass) const {
   //check if user is a default-constructed user
   if (uname == "") return false;
   //check if username and password match the arguments
   if (uname == username && pass == password) {
      return true;
   }
   //if they didn't match, a wrong user/pass combo was submitted
   return false;
}

void User::set_password(const string& newpass) {
   password = newpass;
}
