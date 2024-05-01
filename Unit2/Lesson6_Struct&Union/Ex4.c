/* Master Embedded System Diploma
 * Kerolos Shenoda
 * Learn In Dipth
 * Made By Ahmed Basem Mohamed
 *
 *
 * ****************** EX 4 ***************
 */
#include <stdio.h>
#include <string.h>
#include <math.h>

struct Sstudent
{
    char name[50];
    int roll;
    float marks;
};

void scanStud(struct Sstudent *myStudent)
{
    printf("Enter roll: ");
    fflush(stdin); fflush(stdout);
    scanf("%d", &(myStudent->roll));

    printf("Enter name: ");
    fflush(stdin); fflush(stdout);
    scanf("%s", myStudent->name);

    printf("Enter marks: ");
    fflush(stdin); fflush(stdout);
    scanf("%f", &(myStudent->marks));
}

void printStud(struct Sstudent myStudent)
{
    printf("Information for roll number %d\t", myStudent.roll);
    printf("Name: %s\t", myStudent.name);
    printf("Marks: %0.2f\n", myStudent.marks);
}

int main(void)
{
    struct Sstudent students[10];
    int i;

    printf("Enter information of students: \n");
    fflush(stdin); fflush(stdout);
    for (i = 0; i < 2; i++)
    {
        scanStud(&(students[i]));
    }

    printf("Displaying information of students:\n");
    for (i = 0; i < 2; i++)
    {
        printStud(students[i]);
    }

    return 0;
}

