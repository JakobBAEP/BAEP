
#include <stdio.h>
#include <stdlib.h>
#include "uni.h"

void printUniversity(struct university* uni){
	int students=0;
	int groups=0;
	if (uni->groupList==NULL){
		printf("\n" "University: no groups\n");
		return;
	}

	group *itr =  uni->groupList;
	while (itr!=NULL){
		printf("\n" "%d%c - %d",itr->sem,itr->idx,itr->studentCounter);
		fflush(stdout);
		students = students + itr->studentCounter;
		groups++;
		itr = itr->next;
	}

	printf("\n" "Total: %d Students - %d Groups" ,students,groups);
	fflush(stdout);

	printf("\n" "University is operating since %d semester(s)\n" ,uni->age);
}


void printSemester(struct university *uni) {
	int sem = 0;
	int students = 0;
	int groups = 0;

	if (uni->groupList==NULL){
		printf("\n" "University: no groups\n");
		return;
	}

	printf("\n" "Enter a semester (1-6):");
	fflush(stdout);
	scanf("%d", &sem);
	fflush(stdin);

	group *itr = uni->groupList;
	while (itr != NULL) {
		if (itr->sem == sem) {
			printf("\n" "%d%c - %d", itr->sem, itr->idx, itr->studentCounter);
			fflush(stdout);
			students = students + itr->studentCounter;
			groups++;
		}
		itr = itr->next;
	}
	if (groups>0){
		printf("\n" "Total: %d Students - %d Groups\n", students, groups);
	} else {
		printf("\n" "University: no groups\n");
	}

}


void printGroup(struct university *uni) {
	int sem;
	char idx;

	if (uni->groupList == NULL) {
		printf("\n" "University: no groups\n");
		return;
	}

	printf("\n" "Enter a group (e.g.: 2B):");
	fflush(stdout);
	scanf("%d%c", &sem, &idx);
	fflush(stdin);

	group *itr = uni->groupList;
	while (itr != NULL) {
		if (itr->sem == sem && itr->idx == idx) {
			printf("\n" "Group %d%c has %d students\n", itr->sem, itr->idx, itr->studentCounter);
			return;
		}
		itr = itr->next;
	}
	printf("\n" "This group is not available\n");

}

void insertGroup(struct university *uni,char idx,int students){
	group *temp = malloc(sizeof(group));
	temp->sem=1;
	temp->idx=idx;
	temp->studentCounter = students;
	temp->next=uni->groupList;
	uni->groupList=temp;
}

void incSemester(struct university *uni){
	group *itr =  uni->groupList;
	group *prev = NULL;
	group *temp = NULL;
	while (itr!=NULL){
		if (itr->sem < 6){
			itr->sem = itr->sem + 1;
			prev=itr;
			itr=itr->next;
		} else {
			prev->next = itr->next;
			temp = itr;
			itr=itr->next;
			free(temp);
		}
	}

	uni->age = uni->age +1;
}

void addSemester(university *uni) {
	int nstud=0;
	printf("\n" "Enter the number of students: ");
	fflush(stdout);
	scanf("%d",&nstud);
	fflush(stdin);

	if (nstud > 0 && nstud <= 780) {
		if (nstud < 15) {
			incSemester(uni);
			printf("\n" "Not enough students\n");
			fflush(stdout);

		} else if (nstud <= 30) {
			incSemester(uni);
			insertGroup(uni, 'A', nstud);

		} else if (nstud < 40) {
			incSemester(uni);
			insertGroup(uni, 'B', nstud / 2 + nstud % 2);
			insertGroup(uni, 'A', nstud / 2);

		} else {
			int groups;
			int studpergrp = 19;
			int rest;

			do {
				studpergrp++;
				groups = nstud / studpergrp;
			} while (groups > 26);
			rest = (nstud % studpergrp) % groups;

			incSemester(uni);
			for (int i = groups - 1; i >= 0; i--) {
				insertGroup(uni, 'A' + i,
				studpergrp + (nstud % studpergrp) / groups + (i >= (groups - rest) ? 1 : 0));
			}
		}
	} else {
		printf("\n" "Out of Range");
		fflush(stdout);
	}
}

void freegroups(university *uni) {
	group *itr = uni->groupList;
	group *temp = NULL;
	while (itr != NULL) {
		temp = itr;
		itr = itr->next;
		free(temp);
	}
	uni->groupList=NULL;
}

