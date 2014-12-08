//  =============== BEGIN ASSESSMENT HEADER ================
/// @file BBoard.cpp
/// @brief assn4
///
/// @author Samuel Rufer [srufe001@ucr.edu]
/// @date November 13, 2014
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#include "BBoard.h"
#include "User.h"
#include "Message.h"
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

BBoard::BBoard()
: title("ADD A TITLE, DOOFUS"), user_list(), current_user(0), message_list()
{ }

BBoard::BBoard(const string& ttl)
: title(ttl), user_list(), current_user(0), message_list()
{ }

BBoard::~BBoard() {
   //delete all messages in message_list
   delete curret_user;
}

void BBoard::load_users(const string& input_file) {
   ifstream fin(input_file.c_str());
   if (!fin.is_open()) {
      cout << "Error opening " << input_file << endl;
      exit(0);
   }
   while (!fin.eof()) {
      string uname, pass;
      fin >> uname;
      if (uname == "end") {
         break;
      }
      fin >> pass;
      user_list.push_back(User(uname, pass));
   }
}

void BBoard::login() {
   cout << "Welcome to " << title << endl;
   while(true) {
      string uname, pass;
      cout << "Enter your username ('Q' or 'q' to quit): ";
      cin >> uname;
      if (uname == "q" || uname == "Q") {
         cout << "Bye!" << endl;
         exit(0);
      }
      cout << "Enter your password: ";
      cin >> pass;
      for (int i = 0; i < user_list.size(); ++i) {
         if (user_list.at(i).check(uname, pass)) {
            current_user = user_list.at(i);
            cout << "Welome back " << current_user.get_username() << "!"
                 << endl << endl;
            return;
         }
      }
      cout << "Invalid Username or Password!" << endl << endl;
   }
}

void BBoard::run() {
   if (current_user.get_username() == "") {
      cout << "You must login before using the bulletin board" << endl;
      return;
   }
   //main loop (ask for q n or d)
   while (true) {
      //cout instructions
      cout << "Menu" << endl;
      cout << "  - Display Messages ('D' or 'd')" << endl;
      cout << "  - Add New Message ('N' or 'n')" << endl;
      cout << "  - Quit ('Q' or 'q')" << endl;
      cout << "Choose an action: ";
      string choice;
      cin >> choice;
      // if q
      if (choice == "q" || choice == "Q") {
         cout << "Bye!" << endl;
         exit(0);
      }
      // if n
      else if (choice == "n" || choice == "N") {
         cout << endl;
         //get input from user
         cout << "Enter Subject: ";
         cin.ignore();
         string subject;
         getline(cin, subject);
         cout << "Enter Body: ";
         string body;
         getline(cin, body);
         //add a new message
         message_list.push_back(Message(current_user.get_username(), subject,
                                        body));
         cout << "Message recorded!" << endl;
         cout << endl;
      }
      // if d
      else if (choice == "d" || choice == "D") {
         cout << endl;
         display_messages();
         cout << endl;
      }
      // if neither, give feedback and continue
      else {
         cout << choice << " is not a valid action." << endl << endl;
      }
   }
}

void BBoard::display_messages() const {
   //check if there are any message
   if (message_list.size() == 0) {
      cout << "Nothing to display." << endl;
      return;
   }
   //display messages
   cout << "----------------------------------------" << endl;
   for (int i = 0; i < message_list.size(); ++i) {
      cout << "Message #" << i + 1 << ": ";
      message_list.at(i).display();
      cout << "----------------------------------------" << endl;
   }
}
