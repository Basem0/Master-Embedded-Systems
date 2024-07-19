/*
 * main.c
 *
 *  Created on: Jul 19, 2024
 *      Author: Ahmed Basem
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "StudentManagement.h"

int main()
{
	char temp_text[40];
	char filename[40] = "read.txt";
	char flag = 1;
	setup();

	DPRINTF("Welcome to the Student Management System \n\n");
	while(flag)
	{
		DPRINTF("\n =========================== \n");
		DPRINTF("\n\t Choose The Task that you want to perform \n");
		DPRINTF("\n\t 1. Add the Student Details From Text File \n");
		DPRINTF("\n\t 2. Add the Student Detials Manually \n");
		DPRINTF("\n\t 3. Find the Student Details by Roll Number \n");
		DPRINTF("\n\t 4. Find the Student Details by First Name \n");
		DPRINTF("\n\t 5. Find the Student Details by Course ID \n");
		DPRINTF("\n\t 6. Find the Total number of Students \n");
		DPRINTF("\n\t 7. Delete the Students Details by Roll Number \n");
		DPRINTF("\n\t 8. Update the Students Details by Roll Number \n");
		DPRINTF("\n\t 9. Show all information \n");
		DPRINTF("\n\t 10. To Exit \n");

		DPRINTF("\n Enter your choice to perform the task: ");

		gets(temp_text);
		DPRINTF("\n =========================== \n");
		switch(atoi(temp_text))
		{
		case 1:
			DPRINTF(" Enter file Name: ");
			gets(filename);
			add_students_from_file(filename);
			break;
		case 2:
			add_students_manually();
			break;
		case 3:
			findstudent_using_rollnum();
			break;
		case 4:
			findstudents_using_fname();
			break;
		case 5:
			findstudents_using_courseID();
			break;
		case 6:
			total_students();
			break;
		case 7:
			delete_student();
			break;
		case 8:
			update_student_info();
			break;
		case 9:
			show_all_student_info();
			break;
		case 10:
			DPRINTF(" ======== THANK YOU ========\n");
			flag = 0;
			break;

		default:
			DPRINTF("\n Wrong option \n");
			break;
		}
	}
	return 0;
}