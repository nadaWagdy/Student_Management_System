#include "Student.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Validation.h"

int removal_index = -1;
int search_index = -1;

void add_student(Student *students, int *numOfStudents)
{
    if (*numOfStudents >= MAX_STUDENTS) {
        printf("Student database is full. Cannot add more students.\n");
        return;
    }

    while(1)
    {
        char new_name[MAX_CHARACTER];
        printf("Enter student name: ");
        scanf(" %[^\n]", &new_name);
        // fgets(&new_name, sizeof(new_name), stdin);
        // printf("name is: %s ", new_name);
        if(checkTwoWords(new_name))
        {
            strcpy(students[*numOfStudents].student_name, new_name);
            break;
        }
        printf("Please enter a name that consists of first and last name only.\n");
    }

    while(1)
    {
        char new_id[MAX_CHARACTER];
        printf("Enter student id: ");
        scanf(" %[^\n]", &new_id);
        // fgets(new_id, sizeof(new_id), stdin);
        if(checkSevenDigitCode(new_id))
        {
            if(check_id(students, numOfStudents, new_id))
            {
                strcpy(students[*numOfStudents].student_id, new_id);
                break;
            }else
            {
                printf("This id already exists. enter another valid id\n");
            }
        }else
        {
            printf("Invalid id. id must be a 7_digit code with no leading zeros\n");
        }
    }

    while(1)
    {
        char new_gender;
        printf("Enter student gender: ");
        scanf(" %c", &new_gender);
        if(new_gender == 'M' || new_gender == 'F')
        {
            students[*numOfStudents].student_gender = new_gender;
            break;

        }else
        {
            printf("Invalid value for gender. gender must be 'M' or 'F'.\n");
        }
    }

    while(1)
    {
        int new_academic_year;
        printf("Enter student academic year: ");
        scanf(" %d", &new_academic_year);
        if(new_academic_year >=1 && new_academic_year <= FACULTY_MAX_ACADEMIC_YEAR)
        {
            // int *ptr = &students[*numOfStudents].academic_year;
            students[*numOfStudents].academic_year = new_academic_year;
            break;
        }else
        {
            printf("Invalid academic year. year must be between 1 and %d\n", FACULTY_MAX_ACADEMIC_YEAR);
        }
    }

    while(1)
    {
        float new_GPA;
        printf("Enter student GPA: ");
        scanf(" %f", &new_GPA);
        if(new_GPA >= 0 && new_GPA <= 4)
        {
            students[*numOfStudents].GPA = new_GPA;
            break;
        }else
        {
            printf("Invalid GPA. GPA must be between 0 and 4.0.\n");
        }
    }

    (*numOfStudents)++;
    printf("\nNew student added successfully.\n");
}

void remove_students(Student *students, int *numOfStudents)
{
    if(*numOfStudents == 0)
    {
        printf("student database is empty. cannot remove.\n");
        return;
    }

    while(1)
    {
        char id[MAX_CHARACTER];
        printf("enter student id: ");
        scanf(" %[^\n]", &id);
        if(checkSevenDigitCode(id))
        {
            if(!check_id(students, numOfStudents, id))
            {
                // students[removal_index] = null;
                for(int i = removal_index; i < *numOfStudents - 1; i++)
                {
                    students[i] = students[i + 1];
                }
                (*numOfStudents)--;
                printf("\nstudent removed successfully.\n");
                break;
            }else
            {
                printf("This id does not exists. enter another valid id\n");
            }
        }else
        {
            printf("Invalid id. id must be a 7_digit code with no leading zeros\n");
        }
    }
}

void search_by_name(Student *students, int *numOfStudents)
{
    while(1)
    {
        char name[MAX_CHARACTER];
        printf("enter student name: ");
        scanf(" %[^\n]", &name);

        if(checkTwoWords(name))
        {
            if(check_name(students, numOfStudents, name))
            {
                break;
            }else
            {
                printf("student does not exists. enter another valid name\n");
            }
        }else
        {
            printf("Please enter a name that consists of first and last name only.\n");
        }
    }
}

void search_by_id(Student *students, int *numOfStudents)
{
    while(1)
    {
        char id[MAX_CHARACTER];
        printf("enter student id: ");
        scanf(" %[^\n]", &id);
        if(checkSevenDigitCode(id))
        {
            if(!check_id(students, numOfStudents, id))
            {
                printf("\nStudent's data:\n");
                print_one_student(students, &search_index);
                break;
            }else
            {
                printf("This id does not exists. enter another valid id\n");
            }
        }else
        {
            printf("Invalid id. id must be a 7_digit code with no leading zeros\n");
        }
    }
}

void update_student_data(Student *students, int *numOfStudents)
{
    while(1)
    {
        char id[MAX_CHARACTER];
        printf("enter student id: ");
        scanf(" %[^\n]", &id);
        if(checkSevenDigitCode(id))
        {
            if(!check_id(students, numOfStudents, id))
            {
                int val_choice;
                printf("\nchoose the data to update:\n\n");
                printf("1: Academic Year\n");
                printf("2: GPA\n");

                scanf(" %d", &val_choice);
                switch (val_choice)
                {
                case 1:
                    update_academic_year(students, search_index);
                    break;

                case 2:
                    update_gpa(students, search_index);
                    break;
                default:
                    printf("\ninvalid choice. choose operation again.\n");
                    break;
                }
                break;
            }else
            {
                printf("This id does not exists. enter another valid id\n");
            }
        }else
        {
            printf("Invalid id. id must be a 7_digit code with no leading zeros\n");
        }
    }
}

void update_academic_year(Student *students, int index)
{
    while(1)
    {
        int new_academic_year;
        printf("Enter student academic year: ");
        scanf(" %d", &new_academic_year);
        if(new_academic_year >=1 && new_academic_year <= FACULTY_MAX_ACADEMIC_YEAR)
        {
            students[index].academic_year = new_academic_year;
            printf("\nUpdated successfully.\n");
            break;
        }else
        {
            printf("Invalid academic year. year must be between 1 and %d\n", FACULTY_MAX_ACADEMIC_YEAR);
        }
    }
}

void update_gpa(Student *students, int index)
{
    while(1)
    {
        float new_GPA;
        printf("Enter student GPA: ");
        scanf(" %f", &new_GPA);
        if(new_GPA >= 0 && new_GPA <= 4)
        {
            students[index].GPA = new_GPA;
            printf("\nUpdated successfully.\n");
            break;
        }else
        {
            printf("Invalid GPA. GPA must be between 0 and 4.0.\n");
        }
    }
}

void print_students(Student *students, int *numOfStudents)
{
    printf("\nStudent List:\n\n");
    for (int i = 0; i < *numOfStudents; i++) {
        printf("Name: %s\n", students[i].student_name);
        printf("id: %s\n", students[i].student_id);
        printf("Gender: %c\n", students[i].student_gender);
        printf("Academic Year: %d\n", students[i].academic_year);
        printf("GPA: %.2f\n", students[i].GPA);
        printf("--------------------\n\n");
    }
}

void print_one_student(Student *students, int *i)
{
    // printf("\n\nStudent's data:\n\n");
    printf("\nName: %s\n", students[*i].student_name);
    printf("id: %s\n", students[*i].student_id);
    printf("Gender: %c\n", students[*i].student_gender);
    printf("Academic Year: %d\n", students[*i].academic_year);
    printf("GPA: %.2f\n", students[*i].GPA);
    printf("--------------------\n\n");
}
