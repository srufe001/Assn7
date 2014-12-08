//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp
/// @brief assn4
///
/// @author Samuel Rufer [srufe001@ucr.edu]
/// @date November 12, 2014
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#include<iostream>
#include "BBoard.h"

using namespace std;

int main(int argc, char* args[]) {
   BBoard bb("Sam's Bulletin Board");
   if (!(argc >= 2)) {
      cout << "You forgot the input file" << endl;
      return 0;
   }
   bb.load_users(args[1]);
   bb.login();
   bb.run();
   return 0;
}
