/* Master Embedded System Diploma
 * Kerolos Shenoda
 * Learn In Dipth
 * Made By Ahmed Basem Mohamed
 *
 *
 * ****************** EX 1 ***************
 */
#include <stdio.h>
#include <string.h>
#include <math.h>

struct student{
	char name[20];
	int roll;
	int mark;
};

void main()
{
	struct student stud1;
	printf("Enter information of Students :\n");
	printf("Enter the name  \n");
	char name_t[100];
	fflush(stdin);
	fflush(stdout);
	gets(name_t);
	strcpy(stud1.name,name_t);
	printf("Enter the roll  \n");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &stud1.roll);
	printf("Enter the mark  \n");
	fflush(stdin);
	fflush(stdout);
	scanf("%f", &stud1.mark);
	printf("Displaying Information\r\n");
	printf("Name= %s\nRoll= %d\nMark= %0.2f\n",stud1.name,stud1.roll,stud1.mark);

}
