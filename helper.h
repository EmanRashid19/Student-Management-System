#pragma once
typedef struct 
{
    int id;
    char name[20];
    int age;
    char department[50];
    float marks;
}Student;

void addStudent();
void deleteStudent();
void updateStudent();
void searchStudent();
void displayStudents();
