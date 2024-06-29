/*
 * LinkedList.c
 *
 *  Created on: JUNE 29, 2024
 *      Author: AHMED BASEM
 */

#include "LinkedList.h"

void List_init(S_List *list)
{
    if (!list)
    {
        DPRINTF("Error while initiating the list\n");
        return;
    }
    list->head = NULL;
    list->count = 0;
}

void Fill_Student_Data(S_Student *student)
{

    DPRINTF("Enter the student ID: \n");
    scanf("%d", &student->data.ID);

    DPRINTF("Enter the student name: \n");
    gets(student->data.name);

    DPRINTF("Enter the student height: \n");
    scanf("%f", &student->data.height);

    student->P_next = NULL;
}

void List_Add(S_List *list)
{

    if (!list)
    {
        DPRINTF("ERROR while adding student!! \n");
        return;
    }
    S_Student *newStudent = (S_Student *)malloc(sizeof(S_Student));
    Fill_Student_Data(newStudent);

    if (list->head == NULL)
    {
        list->head = newStudent;
        list->count++;
    }
    else
    {
        S_Student *current = list->head;
        while (current->P_next)
        {
            current = (S_Student *)(current->P_next);
        }

        current->P_next = newStudent;
        list->count++;
    }
}

void List_Delete_Student(S_List *list, unsigned int id)
{

    if (!list)
    {
        DPRINTF("ERROR while deleting student!! \n");
        return;
    }

    if (list->head == NULL)
    {
        DPRINTF("The list is empty\n");
        return;
    }

    S_Student *current = list->head;
    S_Student *previous = current;

    if (current->data.ID == id)
    {
        list->head = (S_Student *)current->P_next;
        free(current);
        list->count--;
        DPRINTF("The student is deleted successfully\n");
        return;
    }

    while (current)
    {

        if (current->data.ID == id && current->P_next == NULL)
        {
            previous->P_next = NULL;
            free(current);
            list->count--;
            DPRINTF("The student is deleted successfully\n");
            return;
        }

        else if (current->data.ID == id)
        {
            previous->P_next = current->P_next;
            free(current);
            list->count--;
            DPRINTF("The student is deleted successfully\n");
            return;
        }

        previous = current;
        current = (S_Student *)current->P_next;
    }
    DPRINTF("ID is not found\n");
}

void List_View(S_List *list)
{
    if (!list)
    {
        DPRINTF("ERROR while printing list!! \n");
        return;
    }

    S_Student *current = list->head;
    if (list->head == NULL)
    {
        DPRINTF("The list is empty\n");
        return;
    }
    int i = 1;
    while (current)
    {
        DPRINTF("\nStudent Number %d\n", i);
        DPRINTF("Student ID: %d\n", current->data.ID);
        DPRINTF("Student name: %s\n", current->data.name);
        DPRINTF("Student height: %0.2f\n", current->data.height);

        current = (S_Student *)current->P_next;
        i++;
    }
}

void List_Delete_All(S_List *list)
{
    if (!list)
    {
        DPRINTF("ERROR while deleting student!! \n");
        return;
    }

    S_Student *current = list->head;

    if (list->head == NULL)
    {
        DPRINTF("The list is empty\n");
        return;
    }

    while (current)
    {
        S_Student *temp = current;
        current = (S_Student *)current->P_next;
        free(temp);
    }
    list->head = NULL;
    list->count = 0;
    DPRINTF("The list is deleted successfully\n");
}

S_Student *Get_Nth_Student(S_List *list, unsigned int index)
{
    S_Student *student = NULL;
    int cnt = 0;
    S_Student *current = list->head;
    if (index >= list->count)
    {
        DPRINTF("The index is exceeded the length if the list\n");
        return student;
    }
    while (cnt != index)
    {
        current = (S_Student *)current->P_next;
        cnt++;
    }

    return current;
}

unsigned int Get_Length(S_Student *head)
{
    if (head == NULL)
        return 0;

    return 1 + Get_Length((S_Student *)head->P_next);
}

S_Student *Get_Ntn_back_student(S_List *list, unsigned int index)
{

    S_Student *ref = NULL;
    S_Student *basic;
    if (index > list->count)
    {
        DPRINTF("The index exceeds the list length\n");
        return ref;
    }

    ref = list->head;
    basic = list->head;

    int cnt = 0;
    while (cnt != index)
    {
        ref = (S_Student *)ref->P_next;
        cnt++;
    }
    while (ref)
    {
        ref = (S_Student *)ref->P_next;
        basic = (S_Student *)basic->P_next;
    }
    return basic;
}

S_Student *Get_Middle_Student(S_List *list)
{
    S_Student *student = NULL;
    if (!list)
    {
        DPRINTF("ERROR while deleting student!! \n");
        return student;
    }

    unsigned int n = list->count / 2;
    student = Get_Nth_Student(list, n);
    return student;
}

void Reverse_List(S_List *list)
{
    if (!list)
    {
        DPRINTF("ERROR while deleting student!! \n");
        return;
    }

    S_Student *current = list->head;
    S_Student *prev = NULL;
    S_Student *next = list->head;

    while (current != NULL)
    {

        next = (S_Student *)current->P_next;
        current->P_next = prev;
        prev = (S_Student *)current;
        current = (S_Student *)next;
    }
    list->head = (S_Student *)prev;
    return;
}