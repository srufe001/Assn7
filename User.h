//  =============== BEGIN ASSESSMENT HEADER ================
/// @file User.h
/// @brief assn4
///
/// @author Samuel Rufer [srufe001@ucr.edu]
/// @date November 12, 2014
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#ifndef __USER_H__
#define __USER_H__

#include<string>

using namespace std;

class User
{
 private:
   string username;
   string password;
 public:
   //creates a user with empty name and password.
   User();

   //creates a user with given username and password.
   User(const string& uname, const string& pass);

   //returns the username
   string get_username() const;

   //returns true if the stored username/password matches with the parameters.
   //Otherwise, return false
   //Returns false if uname parameter is an empty string, because a User
   //object with empty username/password can exist
   bool check(const string& uname, const string& pass) const;

   //sets a nwe password
   void set_password(const string& newpass);
};

#endif
