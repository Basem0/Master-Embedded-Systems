/*
 * StudentManagement.c
 *
 *  Created on: Jul 19, 2024
 *      Author: Ahmed Basem
 */

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "string.h"
#include "FIFO.h"
#include "StudentManagement.h"


FIFO_Buf_t FIFO_Student;


void setup()
{
	if(FIFO_init(&FIFO_Student, student, width1) == FIFO_no_error)
		 DPRINTF("fifo init ----- Done \n");
}

void add_students_from_file(char * filename)
{
		FILE *fp = fopen(filename, "r");
		char buffer[100] = {0};
		char* token;
		unsigned char index_info;
	    if (fp == NULL)
	    {
	        DPRINTF("Error: could not open file %s", filename);
	        return;
	    }
	    while (fgets(buffer,100,fp)) //roll fname lname GPA cID
	    {
	    	index_info = 0;
	    	token = strtok(buffer, " ");
            while(token)
            {
            	   if(FIFO_enqueue_specific_info(&FIFO_Student, index_info, token)== -1)
            		   break;
            	   index_info++;
                   token = strtok(NULL," ");
            }
         }
        DPRINTF("[INFO] Students Details is added Successfully \n");
        total_students();
        // close the file
	    fclose(fp);
}

void add_students_manually()
{
	struct sinfo temp_student;
	unsigned char i;
  DPRINTF("Add the Students Detials\n");
  DPRINTF("-------------------------\n");

  DPRINTF("Enter the Roll Number: ");
  scanf("%d",&temp_student.roll);
  if(FIFO_Find_student_with_rollnumber(&FIFO_Student , temp_student.roll) == 0)
  {	  DPRINTF("Enter the first name of student: ");
	  scanf("%s",temp_student.fname);

	  DPRINTF("Enter the last name of student: ");
	  scanf("%s",temp_student.lname);

	  DPRINTF("Enter the GPA you obtained: ");
	  scanf("%f",&temp_student.GPA);

	  DPRINTF("Enter the course ID of each course\n");
	  for(i = 0 ; i < 5 ; i++)
	  {
	     DPRINTF("Course %d id: ",i+1);
	     scanf("%d",&temp_student.cid[i]);
	  }
	  DPRINTF("[INFO] Students Details is added Successfully \n");
      FIFO_enqueue(&FIFO_Student,&temp_student);
      total_students();
  }
}

void findstudent_using_rollnum(){
  DPRINTF(" --------------------------------\n");
  int roll;
  DPRINTF("Enter the Roll Number of the student: ");
  scanf("%d",&roll);

  struct sinfo* temp_student = FIFO_Find_student_with_rollnumber(&FIFO_Student, roll);
  if(temp_student == NULL)
  {
	  DPRINTF("[ERROR] Roll Number %d is not found\n",roll);
  }
  else
  {
	  DPRINTF("The Students Details are \n");
	  DPRINTF("The First name is %s \n",temp_student->fname);
	  DPRINTF("The Last name is %s \n",temp_student->lname);
	  DPRINTF("The GPA is %0.1f \n",temp_student->GPA);
	  DPRINTF("Courses: \n");
	  for(unsigned char i = 0 ; i < 5 ; i++)
	  {
		  DPRINTF("The Course ID is: %d \n",temp_student->cid[i]);
	  }
  }

}

void findstudents_using_fname(){
	 DPRINTF(" --------------------------------\n");
	 char fname[50];
	 DPRINTF("Enter the first name of the student: ");
	 scanf("%s",fname);
	 if(FIFO_Find_student_with_fname(&FIFO_Student, fname) == -1)
	 {
		 DPRINTF("[ERROR] First name %s not found\n",fname);
	 }
}

void findstudents_using_courseID(){
	DPRINTF(" --------------------------------\n");
	int course_id;
    DPRINTF(" Enter the Course ID: ");
	scanf("%d",&course_id);
	if(FIFO_Find_students_with_CID(&FIFO_Student, course_id) == -1)
    {
			 DPRINTF(" [ERROR] Course id %d not found\n",course_id);
	}
}

void total_students(){
	DPRINTF("-------------------------\n");
    DPRINTF("[INFO] The total number of Student is %d \n",FIFO_Student.count);
    DPRINTF("[INFO] You can add up to %d Students \n",FIFO_Student.length);
	DPRINTF("[INFO] You can add %d more Student is \n",FIFO_Student.length - FIFO_Student.count);
}

void delete_student(){
	int roll;
	DPRINTF(" --------------------------------\n");
	DPRINTF("Enter the Roll Number which you want to delete: ");
	scanf("%d",&roll);
	struct sinfo* ptrStudent = FIFO_Find_student_with_rollnumber(&FIFO_Student, roll);
	if(ptrStudent == NULL)
	{
	    DPRINTF("[ERROR] Roll Number %d is not found\n",roll);
	}
	else
	{
		FIFO_delete_student(&FIFO_Student,ptrStudent);
	}

}

void update_student_info(){
	int choice;
	DPRINTF(" --------------------------------\n");
	DPRINTF("Enter the roll number to update the entry: ");
	scanf("%d",&choice);

	struct sinfo* temp_student = FIFO_Find_student_with_rollnumber(&FIFO_Student, choice);
	if(temp_student == NULL)
	{
		DPRINTF("[ERROR] Roll Number %d is not found\n",choice);
	}
	else
	{
		DPRINTF("1. First name \n");
		DPRINTF("2. Last name \n");
		DPRINTF("3. Roll number \n");
		DPRINTF("4. GPA \n");
		DPRINTF("5. courses \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					DPRINTF("Enter the new First name: ");
					scanf("%s",temp_student->fname);
				    break;
			case 2:
					DPRINTF("Enter the new Last name: ");
					scanf("%s",temp_student->lname);
					break;
			case 3:
					DPRINTF("Enter the new Roll number: ");
					scanf("%d",&temp_student->roll);
					break;
			case 4:
					DPRINTF("Enter the new GPA: ");
					scanf("%f",&temp_student->GPA);
					break;
			case 5:
				  for(int i = 0 ; i < 5 ; i++)
				  {
				     DPRINTF("enter the new Course %d id: ",i+1);
				     scanf("%d",&temp_student->cid[i]);
				  }
					break;
			default:
					DPRINTF("Wrong Choice \n");
					return;
		}
		DPRINTF("[INFO] UPDATED SUCCESSFULLY \n");
	}
}

void show_all_student_info(){
	FIFO_print(&FIFO_Student);
}