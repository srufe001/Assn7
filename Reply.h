//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn7/Reply.h
/// @brief Assignment 7 for CS 12 Fall 2014
///
/// @author Samuel Rufer [srufe001@ucr.edu]
/// @date December 3, 2014
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 022
/// @par
///     TA: Ali
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============
#ifndef __REPLY_H__
#define __REPLY_H__

class Reply : public Message {
  public:
   //default constructor
   Reply();
   //parameterized constructor - same as Message's constructor, except subject
   //is initialized to "Re: <sbjct>" rather than "<sbjct>"
   Reply(const string& athr, const string& sbjct, const string& body,
         unsigned id);

   //returns true
   virtual bool is_reply() const;

   /* to_formatted_string writes teh contents of the Reply to a string in the
    * following format:

    <begin_reply>
    :id: 4
    :subject: single line
    :from: author
    :children: 5 6 [see Topic.h]
    :body: line 1
    line 2
    line 3
    <end>

    */
   virtual string to_formatted_string() const;
};
#endif
