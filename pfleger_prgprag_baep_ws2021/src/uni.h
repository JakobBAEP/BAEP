#ifndef UNI_H_
#define UNI_H_


typedef struct group{
	int studentCounter;
	int sem;
	char idx;
	struct group* next;
} group;

typedef struct university{
	struct group* groupList;
	int age;
} university ;

void printUniversity(struct university*);
void printSemester(struct university*);
void printGroup(struct university*);

void insertGroup(university*,char,int);
void incSemester(university*);
void addSemester(university*);
void freegroups(university*);


#endif
