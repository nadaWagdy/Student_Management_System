#ifndef Validation_h
#define Validation_h

#include "Student.h"
#include <stdbool.h>

//------ Validation OPERATIONS
bool checkTwoWords(char str[MAX_CHARACTER]);
/*--------------------------------------------------------------------
Check that a string consists of two words.
Input: a string.
Output: returns a boolean value indicating a string consists of two words or does not.
--------------------------------------------------------------------*/

bool checkSevenDigitCode(char str[MAX_CHARACTER]);
/*--------------------------------------------------------------------
Check that a string consists of 7-digit code and no other characters.
Input: a string.
Output: return a boolean value indicating a string is a 7-digit code or not.
--------------------------------------------------------------------*/

bool check_id(Student *students, int *numOfStudents, char *id);
/*--------------------------------------------------------------------
Check that the given id is unique and no other student have the same id.
Input: an array of students, an integer variable representing number of students in the array and an id string.
Output: return a boolean value indicating id exists or does not.
--------------------------------------------------------------------*/

bool check_name(Student *students, int *numOfStudents, char *name);
/*--------------------------------------------------------------------
Check that a student with the given name exits in the array to print its data.
Input: an array of students, an integer variable representing number of students in the array and a name string.
Output: return a boolean value indicating name exists or does not, if it does exist print all students having the same name.
--------------------------------------------------------------------*/

#endif
