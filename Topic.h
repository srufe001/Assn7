//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn7/Topic.h
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
#ifndef __TOPIC_H__
#define __TOPIC_H__

class Topic : public Message {
  public:
   //default constructor
   Topic();
   //parameterized constructor
   Topic(const string &athr, const string &sbjct, const string &body,
         unsigned id);

   //returns false
   virtual bool is_reply() const;

   /* to_formatted_string writes the contents of the Topic to a string in the
    * following format:

    <begin_topic>
    :id: 4
    :subject: single line
    :from: author
    :children: 5 6 [not included if there are no children]
    :body: line 1
    line 2
    line 3
    <end>
  
    * :children: line has ids of all children
    */
   virtual string to_formatted_string() const;
};
#endif
