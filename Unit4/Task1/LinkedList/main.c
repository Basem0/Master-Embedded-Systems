
/*
 * main.c
 *
 *  Created on: JUNE 29, 2024
 *      Author: AHMED BASEM
 */

#include "LinkedList.h"

int main(){
	char c;
	S_List list;
	List_init(&list);
	int id;
	int index;
	int index_back;

	while(1){
		DPRINTF("=======================================\n");
		DPRINTF("Enter your choice: \n");
		DPRINTF("1 - Add Student to the list\n");
		DPRINTF("2 - Delete student from the list\n");
		DPRINTF("3 - View the students list\n");
		DPRINTF("4 - Delete All the list\n");
		DPRINTF("5 - get the Nth student\n");
		DPRINTF("6 - Get the length of the list\n");
		DPRINTF("7 - Get the Nth student from back\n");
		DPRINTF("8 - get the middle student\n");
		DPRINTF("9 - Reverse the list\n");
		DPRINTF("q - quit\n");
		DPRINTF("=======================================");

		gets(&c);
		switch(c){
		case '1':
			List_Add(&list);
			break;

		case '2':

			DPRINTF("Enter the student ID to be deleted : \n");
			scanf("%d",&id);
			List_Delete_Student(&list,id);
			break;

		case '3':
			List_View(&list);
			break;

		case '4':
			List_Delete_All(&list);
			break;

		case '5':
			DPRINTF("Enter the index: \n");
			scanf("%d",&index);
			S_Student* needed = Get_Nth_Student(&list,index);
			if(needed == NULL){
				DPRINTF("Can't find the student\n");
				break;
			}
			DPRINTF("Student ID : %d\n", needed->data.ID);
			DPRINTF("Student name : %s\n", needed->data.name);
			DPRINTF("Student height : %.2f\n", needed->data.height);
			break;

		case '6':
			DPRINTF("\n The length is %d\n", Get_Length(list.head));
			break;

		case '7':
			DPRINTF("Enter the index from back: \n");
			scanf("%d",&index_back);
			S_Student* needed_back = Get_Ntn_back_student(&list,index_back);
			if(needed_back == NULL){
				DPRINTF("Can't find the student\n");
				break;
			}

			DPRINTF("Student ID : %d\n", needed_back->data.ID);
			DPRINTF("Student name : %s\n", needed_back->data.name);
			DPRINTF("Student height : %.2f\n", needed_back->data.height);
			break;


		case '8':
			DPRINTF("\n");
			S_Student* middle = Get_Middle_Student(&list);
			if(middle == NULL){
				DPRINTF("Can't find the middle student\n");
				break;
			}

			DPRINTF("Student ID : %d\n", middle->data.ID);
			DPRINTF("Student name : %s\n", middle->data.name);
			DPRINTF("Student height : %.2f\n", middle->data.height);
			break;

		case '9':
			DPRINTF("Original list: \n");
			List_View(&list);
			Reverse_List(&list);
			DPRINTF("\nReversed list\n");
			List_View(&list);
			break;
		case 'q':
			c= '0';
			break;

		}
		if (c == '0')
			break;
	}
	return 0;
}
