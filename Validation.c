#include <stdio.h>
#include "Validation.h"
#include <stdbool.h>
#include <string.h>

extern int removal_index;
extern int search_index;

bool checkTwoWords(char str[MAX_CHARACTER]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            count++;
        }
    }
    return count == 1;
}

bool checkSevenDigitCode(char str[MAX_CHARACTER]) {
    int length = strlen(str);
    if (length == 7) {
        if (str[0] != '0') {
            for (int i = 1; i < length ; i++) {
                if (str[i] < '0' || str[i] > '9') {
                    return false;
                }
            }
            return true;
        }
    }

    return false;
}

bool check_id(Student *students, int *numOfStudents, char *id)
{
    for(int i = 0; i < *numOfStudents; i++)
    {
        int count = 0;
        for(int j = 0; j < 7; j++)
            if(students[i].student_id[j] == id[j])
                count++;
        if(count == 7)
        {
            removal_index = i;
            search_index = i;
            return false;
        }
    }
    return true;
}

bool check_name(Student *students, int *numOfStudents, char *name)
{
    bool flag = false;
    for(int i = 0; i < *numOfStudents; i++)
    {
        int count = 0;
        int length = strlen(students[i].student_name);

        for(int j = 0; j < length; j++)
            if(students[i].student_name[j] == name[j])
                count++;
        if(count == length)
        {
            print_one_student(students, &i);
            flag = true;
        }
    }
    return flag;
}
