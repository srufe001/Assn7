//  =============== BEGIN ASSESSMENT HEADER ================
/// @file Message.h
/// @brief assn4
///
/// @author Samuel Rufer [srufe001@ucr.edu]
/// @date November 13, 2014
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include<string>

using namespace std;

class Message {
 protected:
   string author;
   string subject;
   string body;
   unsigned id;
   vector<Message *> child_list;
 public:
   //default constructor
   Message();
   //parameterized constructor
   Message(const string& athr, const string& sbjct, const string& body,
           unsigned id);

   virtual ~Message();
   virtual bool is_reply() const = 0;
   virtual string to_formatted_string() const = 0;
   /* prints the message with the proper indentation (indentation = 1 is 2
    * spaces) and all replies
    */
   void print(unsigned indentation) const;

   //returns the subject string
   const string & get_subject() const;

   //returns the id
   unsigned get_id() const;

   //adds a pointer to a message as a child to this message
   void add_child(Message * child);
};

#endif
