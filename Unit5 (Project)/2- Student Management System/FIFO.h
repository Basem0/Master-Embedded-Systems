/*
 * FIFO.h
 *
 *  Created on: Jul 19, 2024
 *      Author: Ahmed Basem
 */

#ifndef FIFO_H_
#define FIFO_H_

//USER Configuration

//select the element type (uint8_t , uint16_t , uint32_t, struct, ....)
#define element_type struct sinfo

//create buffer
#define width1 55

//FIFO data types
typedef struct {
	unsigned int length;
	unsigned int count ;
	element_type* base ;
	element_type* head ;
	element_type* tail ;
}FIFO_Buf_t;

typedef enum{
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_null
}FIFO_Buf_Status;

//FIFO APIs

FIFO_Buf_Status FIFO_init(FIFO_Buf_t * fifo ,element_type* buf , uint32_t length);
FIFO_Buf_Status FIFO_enqueue(FIFO_Buf_t * fifo ,element_type* item);
FIFO_Buf_Status FIFO_dequeue(FIFO_Buf_t * fifo ,element_type* item);
FIFO_Buf_Status FIFO_IS_FULL(FIFO_Buf_t * fifo);
FIFO_Buf_Status FIFO_IS_Empty(FIFO_Buf_t * fifo);
void FIFO_print(FIFO_Buf_t * fifo);


char FIFO_enqueue_specific_info(FIFO_Buf_t * fifo, char index_info, char* token);
element_type* FIFO_Find_student_with_rollnumber(FIFO_Buf_t * fifo, int roll);
char FIFO_Find_student_with_fname(FIFO_Buf_t * fifo, char * fname);
char FIFO_Find_students_with_CID(FIFO_Buf_t * fifo,int courseId);
void FIFO_delete_student(FIFO_Buf_t * fifo, element_type* item);

#endif /* FIFO_H_ */