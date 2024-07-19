/*
 * FIFO.c
 *
 *  Created on: Jul 19, 2023
 *      Author: Ahmed Basem
 */

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "FIFO.h"
#include "string.h"
#include "StudentManagement.h"




FIFO_Buf_Status FIFO_init(FIFO_Buf_t * fifo ,element_type* buf , uint32_t length)
{
	if(buf == NULL)
		return FIFO_null;
	fifo->base   = buf;
	fifo->head   = buf;
	fifo->tail   = buf;
	fifo->length = length;
	fifo->count  = 0;

	return FIFO_no_error ;
}

FIFO_Buf_Status FIFO_enqueue(FIFO_Buf_t * fifo ,element_type* item)
{
	if (!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;

	//fifo is full
	if(FIFO_IS_FULL(fifo) == FIFO_full)
		return FIFO_full ;

	*(fifo->head) = *item ;
	fifo->count++;

	//circular fifo
	if (fifo->head == fifo->base + (fifo->length -1 ))
		fifo->head = fifo->base;
	else
		fifo->head++;

	return FIFO_no_error ;
}

FIFO_Buf_Status FIFO_dequeue(FIFO_Buf_t * fifo ,element_type* item)
{
	if (!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;

	//fifo is empty
	if(FIFO_IS_Empty(fifo) == FIFO_empty)
		return FIFO_empty ;

	*item = *(fifo->tail);
	fifo->count--;

	//circular fifo
	if (fifo->tail == fifo->base + (fifo->length -1 ))
		fifo->tail = fifo->base;
	else
		fifo->tail++;

	return FIFO_no_error ;
}

FIFO_Buf_Status FIFO_IS_FULL(FIFO_Buf_t * fifo)
{
	if(!fifo->base || !fifo->head || !fifo->tail)
			return FIFO_null;

	if (fifo->count == fifo->length)
		return FIFO_full ;

	return FIFO_no_error ;
}

FIFO_Buf_Status FIFO_IS_Empty(FIFO_Buf_t * fifo)
{
	if (fifo->count == 0)
		return FIFO_empty ;

	return FIFO_no_error ;
}
void FIFO_print(FIFO_Buf_t * fifo)
{
	element_type * temp ;
	if (fifo->count == 0)
	{
		DPRINTF("fifo is empty \n");
	}
	else
	{
		temp = fifo ->tail;
		unsigned char i,j;
		for (i=0 ; i<fifo->count ; i++)
		{
			DPRINTF(" --------------------------------\n");
			DPRINTF("Student first name: %s \n",temp->fname);
			DPRINTF("Student last name: %s \n",temp->lname);
			DPRINTF("Student roll number: %d \n",temp->roll);
			DPRINTF("Student GPA number: %0.1f \n",temp->GPA);
			for(j = 0 ; j < 5 ; j++)
			{
				DPRINTF("The Course ID is: %d \n",temp->cid[j]);
			}
			//circular fifo
			if (temp == fifo->base + (fifo->length -1 ))
				temp = fifo->base;
			else
				temp++;
		}
		DPRINTF(" --------------------------------\n");
	}

}

element_type* FIFO_Find_student_with_rollnumber(FIFO_Buf_t * fifo, int roll)
{
	element_type* ptr = fifo->tail;
	 for(char index =0 ; index < fifo->count ; index++)
	  {
	      if(roll == ptr->roll)
	      {
	        return ptr;
	      }
	      else
	      {
	    	  if (ptr == fifo->base + (fifo->length -1 ))
	    	  		ptr = fifo->base;
	    	  else
	    	  		ptr++;
	      }
	  }
	  return NULL;
}

char FIFO_Find_student_with_fname(FIFO_Buf_t * fifo, char * fname)
{
	element_type* ptr = fifo->tail;
	char flag = -1;
	for(char index =0 ; index < fifo->count ; index++)
	{
	     if(strcmp(fname,ptr->fname) == 0)
	     {
	         flag = 0;
	    	 DPRINTF(" --------------------------------\n");
	    	 DPRINTF("The Students Details are \n");
	    	 DPRINTF("The First name is %s \n",ptr->fname);
	    	 DPRINTF("The Last name is %s \n",ptr->lname);
	    	 DPRINTF("The Roll Number is %d",ptr->roll);
	    	 DPRINTF("The GPA is %0.1f \n",ptr->GPA);
	    	 DPRINTF("Courses: \n");
	    	 for(unsigned char i = 0 ; i < 5 ; i++)
	    	 {
	    	     DPRINTF("The Course ID is: %d \n",ptr->cid[i]);
	    	 }
	     }
	     if (ptr == fifo->base + (fifo->length -1 ))
	    	 ptr = fifo->base;
	     else
	    	 ptr++;

	}
	return flag;
}

char FIFO_Find_students_with_CID(FIFO_Buf_t * fifo, int courseId){
	element_type* ptr = fifo->tail;
    char flag = -1;
    char counter = 0;
    unsigned char course;
    for(char index =0 ; index < fifo->count ; index++)
    {
         for(course = 0 ; course < 5 ; course++)
         {
        	 if((courseId == ptr->cid[course] ))
        	 {
        	     flag = 0;
        	     DPRINTF(" --------------------------------\n");
        	     DPRINTF(" The Students Details are \n");
        	     DPRINTF(" The First name is %s \n",ptr->fname);
        	     DPRINTF(" The Last name is %s \n",ptr->lname);
        	     DPRINTF(" The Roll Number is %d",ptr->roll);
        	     DPRINTF(" The GPA is %0.1f \n",ptr->GPA);
        	     counter++;
        	     break;
        	 }
         }
         if (ptr == fifo->base + (fifo->length -1 ))
          	 ptr = fifo->base;
         else
           	 ptr++;
    }
    if(counter != 0)
    	DPRINTF(" [INFO] Total Number of Students Enrolled: %d \n",counter);
    return flag;
}
char FIFO_enqueue_specific_info(FIFO_Buf_t * fifo, char index_info, char* token)
{
		unsigned char course_index = 0;
        int roll;
		switch(index_info)
		{
			case ROLL_NUMNBER_INDEX:
				 	 	 roll = atoi(token);
				         if(FIFO_Find_student_with_rollnumber(fifo , roll) != NULL)
				          {
				        	  DPRINTF("[ERROR] Roll Number %d is already taken \n",roll);
				        	  return -1;
				          }
				         else
				          {
				        	  fifo->head->roll = roll;
				          }
			 	 	 	 break;
			case  F_NAME_INDEX:
		                 strcpy(fifo->head->fname,token);
		                 break;
			case L_NAME_INDEX:
	 		 	 	 	 strcpy(fifo->head->lname,token);
	 		 	 	 	 break;
			case GPA_INDEX:
						 fifo->head->GPA = atof(token);
	 		 	 	 	 break;
			case CID_INDEX:
	 		 	 	 	 while(token)
	 		             {
	 		            	 fifo->head->cid[course_index] = atoi(token);
	 		            	 course_index++;
	 		            	 token = strtok(NULL, " ");
	 		             }
	 	                 DPRINTF("[INFO] Roll Number %d saved successfully\n",fifo->head->roll);
	 	                 //circular fifo
	 	                 if (fifo->head == fifo->base + (fifo->length -1 ))
	 	                	 fifo->head = fifo->base;
	 	                 else
	 	                	 fifo->head++;
	 		 	 	 	 fifo->count++;
	 		 	 	 	 break;
		}
		return 0;
}

void FIFO_delete_student(FIFO_Buf_t * fifo, element_type* item){
	int roll = item->roll;
	struct sinfo* ptrNext = item;
    while(ptrNext != fifo->head)
    {
    	//circular fifo
    	if (ptrNext == fifo->base + (fifo->length - 1))
    		ptrNext = fifo->base;
    	else
    		ptrNext++;
    	*item = *ptrNext;
    	 item = ptrNext;
    }
    DPRINTF("[INFO] Roll Number %d is removed Successfully \n",roll);
    fifo->head--;
    fifo->count--;
}