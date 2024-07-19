/*
 * StudentManagement.h
 *
 *  Created on: Jul 19, 2024
 *      Author: Ahmed Basem
 */

#ifndef STUDENTMANAGEMENT_H_
#define STUDENTMANAGEMENT_H_

#define DPRINTF(...) {fflush(stdout); \
                      fflush(stdin); \
					  printf(__VA_ARGS__); \
					  fflush(stdout); \
                      fflush(stdin); }

#define ROLL_NUMNBER_INDEX     0
#define F_NAME_INDEX           1
#define L_NAME_INDEX           2
#define GPA_INDEX              3
#define CID_INDEX              4


struct sinfo {
	char fname[50];
	char lname[50];
	int roll;
	float GPA;
	int cid[10];
} student[55];

void setup();
void add_students_from_file(char * filename);
void add_students_manually();
void findstudent_using_rollnum();
void findstudents_using_fname();
void findstudents_using_courseID();
void total_students();
void delete_student();
void update_student_info();
void show_all_student_info();

#endif /* STUDENTMANAGEMENT_H_ */