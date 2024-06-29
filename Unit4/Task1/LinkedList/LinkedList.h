/*
 * LinkedList.h
 *
 *  Created on: JUNE 29, 2024
 *      Author: AHMED BASEM
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define DPRINTF(...)         \
    {                        \
        fflush(stdin);       \
        fflush(stdout);      \
        printf(__VA_ARGS__); \
        fflush(stdin);       \
        fflush(stdout);      \
    }

typedef struct
{
    int ID;
    char name[40];
    float height;
} S_Data;

typedef struct
{
    S_Data data;
    struct S_Student *P_next;
} S_Student;

typedef struct
{
    S_Student *head;
    unsigned int count;
} S_List;

// APIs
void List_init(S_List *list);
void Fill_Student_Data(S_Student *student);
void List_Add(S_List *list);
void List_Delete_Student(S_List *list, unsigned int id);
void List_Delete_All(S_List *list);
void List_View(S_List *list);
S_Student *Get_Nth_Student(S_List *list, unsigned int index);
unsigned int Get_Length(S_Student *head);
S_Student *Get_Ntn_back_student(S_List *list, unsigned int index);
S_Student *Get_Middle_Student(S_List *list);
void Reverse_List(S_List *list);

#endif /* LINKEDLIST_H_ */