#include <stdio.h>
#include "Student.h"
#include <stdbool.h>

int main()
{
    Student students[MAX_STUDENTS];
    int numOfStudents = 0;

    /*    laod data from file     */
    FILE *file = fopen("students.dat", "rb");
    if (file != NULL) {
        Student student;
        int instanceCount = 0;

        while (fread(&student, sizeof(Student), 1, file) == 1) {
            students[numOfStudents] = student;
            numOfStudents++;
        }

        fclose(file);
    }
    /* ************************** */

    printf("/**********************************************************************************/\n");
    printf("\t\t\tStudent Management System\t\t\n");
    printf("/**********************************************************************************/\n");

    bool flag = 1;
    do
    {
        printf("\nChoose the desired operation:\n\n");
        printf("\t1: Add a new student\n");
        printf("\t2: Remove a student\n");
        printf("\t3: Retrieve student's data\n");
        printf("\t4: update student's data\n");
        printf("\t5: exit system\n");
        int choice, search_way;
        scanf(" %d", &choice);

        switch (choice)
        {
        case 1:
            add_student(students, &numOfStudents);
            break;

        case 2:
            remove_students(students, &numOfStudents);
            break;

        case 3:
            if(numOfStudents == 0)
            {
                printf("student database is empty. cannot retrieve.\n");
                break;
            }
            printf("Choose the search way:\n\n");
            printf("1: Search by Name\n");
            printf("2: Search by ID\n");
            scanf(" %d", &search_way);

            switch (search_way)
            {
                case 1:
                    search_by_name(students, &numOfStudents);
                    break;

                case 2:
                    search_by_id(students, &numOfStudents);
                    break;

                default:
                    printf("\ninvalid choice. choose operation again.\n");
                    break;
            }
            break;

        case 4:
            update_student_data(students, &numOfStudents);
            break;

        case 5:
            flag = 0;
            break;

        default:
            printf("Invalid Choice. Please enter a valid number\n");
            break;
        }

    }while(flag);

    /*     save data to file     */
    file = fopen("students.dat", "wb");
    if (file != NULL) {
        fwrite(students, sizeof(Student), numOfStudents, file);
        fclose(file);
    }
    /* ************************* */
}
