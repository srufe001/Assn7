//  =============== BEGIN ASSESSMENT HEADER ================
/// @file Message.cpp
/// @brief assn4
///
/// @author Samuel Rufer [srufe001@ucr.edu]
/// @date November 13, 2014
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#include "Message.h"
#include<string>
#include<iostream>

using namespace std;

Message::Message()
: author(), subject(), body(), id(0)
{ }

Message::Message(const string& athr, const string& sbjct, const string& body,
                 unsigned id)
: author(athr), subject(sbjct), body(body), id(id)
{ }

void Message::print(unsigned indentation) const {
   //create the indent
   string indent = "";
   for (int i = 0; i < indentation; ++i) indent += "  ";
   string message_string = to_formatted_string();
   //TODO
   for (int i = 0; i < child_list.length(); ++i) {
      child_list.at(i).print(indentation + 1);
   }
}

const string & Message::get_subject() const {
   return subject;
}

unsigned Message::get_id() const {
   return id;
}

void Message::add_child(Message * child) {
   child_list.push_back(child);
}
