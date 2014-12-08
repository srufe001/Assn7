//  =============== BEGIN ASSESSMENT HEADER ================
/// @file BBoard.h
/// @brief assn4
///
/// @author Samuel Rufer [srufe001@ucr.edu]
/// @date November 13, 2014
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#ifndef __BBOARD_H__
#define __BBOARD_H__

#include<vector>
#include<string>
#include "User.h"
#include "Message.h"

using namespace std;

class BBoard {
 private:
   string title;
   vector<User> user_list;
   const User * current_user;
   vector<Message *> message_list;
 public:
   BBoard();
   BBoard(const string& ttl);
   ~BBoard();
   bool load_users(const string & userfile);
   bool load_messages(const string & datafile);
   bool save_messages(const string & datafile);
   void login();
   void run();
 private:
   void display_messages() const;
};

#endif
