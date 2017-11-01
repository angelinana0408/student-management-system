#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Student{
    int Num;
    char Name[20];
    char Sex;
    int Age;
    float MScore;
    float EScore;
    float CScore;
} Student;

typedef struct Node{
    Student data;
    struct Node* next;
}Node,*pNode;
pNode stuList;//@@@@@@@@@@@@@@@@@@@@@@@@@@@@

int addNode(Student* pStu);
Student* tra(int* pn);
int deleteNode(char* n);
int init();
void release();
