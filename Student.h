#ifndef Student_h
#define Student_h

#define MAX_STUDENTS 5
#define FACULTY_MAX_ACADEMIC_YEAR 5
#define MAX_CHARACTER 200
#include <stdio.h>

//-- struct of Student
typedef struct
{
    //------ Student DATA MEMBERS
    char student_name[MAX_CHARACTER];
    char student_id[MAX_CHARACTER];
    char student_gender;
    int academic_year;
    float GPA;
} Student;

//------ Student OPERATIONS
void add_student(Student *students, int *numOfStudents);
/*--------------------------------------------------------------------
Add a student to a list of students and increment the number of students in the system by one.
Input: an array of students and integer variable representing number of students in the array.
Postcondition: New Student added to the array of students.
--------------------------------------------------------------------*/

void print_students(Student *students, int *numOfStudents);
/*--------------------------------------------------------------------
Print all students data in an array.
Input: an array of students and integer variable representing number of students in the array.
Postcondition: All students data in the array printed.
--------------------------------------------------------------------*/

void print_one_student(Student *students, int *i);
/*--------------------------------------------------------------------
Print one Student data from an array.
Input: an array of students and integer variable representing the index of the desired student to be printed.
Postcondition: The student data at the givin index is printed.
--------------------------------------------------------------------*/

void remove_students(Student *students, int *numOfStudents);
/*--------------------------------------------------------------------
Remove a Student from an array.
Input: an array of students and integer variable representing number of students in the array.
Postcondition: Student data removed from the array.
--------------------------------------------------------------------*/

void search_by_name(Student *students, int *numOfStudents);
/*--------------------------------------------------------------------
Search a Student in an array by its name.
Input: an array of students and integer variable representing number of students in the array.
Postcondition: All Students matching with the name their data is printed.
--------------------------------------------------------------------*/

void search_by_id(Student *students, int *numOfStudents);
/*--------------------------------------------------------------------
Search a Student in an array by its id.
Input: an array of students and integer variable representing number of students in the array.
Postcondition: Data of The Student whose id matching with the entered id is printed.
--------------------------------------------------------------------*/

void update_student_data(Student *students, int *numOfStudents);
/*--------------------------------------------------------------------
Update a Student data.
Input: an array of students and integer variable representing number of students in the array.
Postcondition: A choice is displayed to the user to choose either to change academic year or gpa.
--------------------------------------------------------------------*/

void update_academic_year(Student *students, int index);
/*--------------------------------------------------------------------
Update the value of a student's academic year.
Input: an array of students and integer variable representing the index of the desired student to be updated.
Postcondition: Student's academic year updated.
--------------------------------------------------------------------*/

void update_gpa(Student *students, int index);
/*--------------------------------------------------------------------
Update the value of a student's gpa.
Input: an array of students and integer variable representing the index of the desired student to be updated.
Postcondition: Student's gpa updated.
--------------------------------------------------------------------*/

#endif
