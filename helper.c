#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helper.h"

void addStudent(){
    Student temp;
    printf("Enter student ID: ");
    scanf("%d", &temp.id);
    printf("Enter Name: ");
    scanf("%s", temp.name);
    printf("Enter age: ");
    scanf("%d", &temp.age);
    printf("Enter Department: ");
    scanf("%s", temp.department);
    printf("Enter marks: ");
    scanf("%lf", &temp.marks);

    FILE *fp = fopen("data.txt","a");
    if (fp == NULL){
        printf("error occured");
    }
    fprintf(fp ,"%-10d | %-20s | %-4d | %-20s | %-6.2lf \n ", temp.id , temp.name, temp.age ,temp.department , temp.marks);
    fclose(fp);
}

void displayStudents() {
    Student temp;
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("No student records found.\n");
        return;
    }
    printf("\n-------------------------------------------------------------\n");
    printf("%-10s %-20s %-5s %-20s %-10s\n",
           "ID", "Name", "Age", "Department", "Marks");
    printf("-------------------------------------------------------------\n");

    while (fscanf(fp, "%d %49s %d %49s %lf",
                  &temp.id,
                  temp.name,
                  &temp.age,
                  temp.department,
                  &temp.marks) == 5) {

        printf("%-10d %-20s %-5d %-20s %-10.2lf\n",
               temp.id,
               temp.name,
               temp.age,
               temp.department,
               temp.marks);
    }

    fclose(fp);
}

void searchStudent() {
    Student temp;
    int id;
    int found = 0;

    printf("\nEnter student ID to search: ");
    scanf("%d", &id);

    FILE *fp = fopen("data.txt", "r");

    if (fp == NULL) {
        printf("No student records found.\n");
        return;
    }

    while (fscanf(fp, "%d %49s %d %49s %lf",
                  &temp.id,
                  temp.name,
                  &temp.age,
                  temp.department,
                  &temp.marks) == 5) {

        if (temp.id == id) {
            printf("\nStudent Found!\n");
            printf("ID: %d\n", temp.id);
            printf("Name: %s\n", temp.name);
            printf("Age: %d\n", temp.age);
            printf("Department: %s\n", temp.department);
            printf("Marks: %.2lf\n", temp.marks);

            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

void deleteStudent() {
    Student temp;
    int id;
    int found = 0;

    printf("\nEnter student ID to delete: ");
    scanf("%d", &id);

    FILE *fp = fopen("data.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (fp == NULL || tempFile == NULL) {
        printf("Error opening file.\n");

        if (fp != NULL)
            fclose(fp);

        if (tempFile != NULL)
            fclose(tempFile);

        return;
    }

    while (fscanf(fp, "%d %49s %d %49s %lf",
                  &temp.id,
                  temp.name,
                  &temp.age,
                  temp.department,
                  &temp.marks) == 5) {

        if (temp.id == id) {
            found = 1;
            continue;
        }

        fprintf(tempFile, "%d %s %d %s %.2lf\n",
                temp.id,
                temp.name,
                temp.age,
                temp.department,
                temp.marks);
    }

    fclose(fp);
    fclose(tempFile);

    remove("data.txt");
    rename("temp.txt", "data.txt");

    if (found)
        printf("Student deleted successfully!\n");
    else
        printf("Student not found.\n");
}


/* Update Student */
void updateStudent() {
    Student temp;
    int id;
    int found = 0;

    printf("\nEnter student ID to update: ");
    scanf("%d", &id);

    FILE *fp = fopen("data.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (fp == NULL || tempFile == NULL) {
        printf("Error opening file.\n");

        if (fp != NULL)
            fclose(fp);

        if (tempFile != NULL)
            fclose(tempFile);

        return;
    }

    while (fscanf(fp, "%d %49s %d %49s %lf",
                  &temp.id,
                  temp.name,
                  &temp.age,
                  temp.department,
                  &temp.marks) == 5) {

        if (temp.id == id) {
            found = 1;

            printf("\nEnter new name: ");
            scanf("%49s", temp.name);

            printf("Enter new age: ");
            scanf("%d", &temp.age);

            printf("Enter new department: ");
            scanf("%49s", temp.department);

            printf("Enter new marks: ");
            scanf("%lf", &temp.marks);
        }

        fprintf(tempFile, "%d %s %d %s %.2lf\n",
                temp.id,
                temp.name,
                temp.age,
                temp.department,
                temp.marks);
    }

    fclose(fp);
    fclose(tempFile);

    remove("data.txt");
    rename("temp.txt", "data.txt");

    if (found)
        printf("Student updated successfully!\n");
    else
        printf("Student not found.\n");
}


/* Count Students */
void countStudents() {
    Student temp;
    int count = 0;

    FILE *fp = fopen("data.txt", "r");

    if (fp == NULL) {
        printf("Total students: 0\n");
        return;
    }

    while (fscanf(fp, "%d %49s %d %49s %lf",
                  &temp.id,
                  temp.name,
                  &temp.age,
                  temp.department,
                  &temp.marks) == 5) {
        count++;
    }

    fclose(fp);

    printf("\nTotal students: %d\n", count);
}


/* Find Student With Highest Marks */
void displayTopStudent() {
    Student temp;
    Student top;
    int found = 0;

    FILE *fp = fopen("data.txt", "r");

    if (fp == NULL) {
        printf("No student records found.\n");
        return;
    }

    while (fscanf(fp, "%d %49s %d %49s %lf",
                  &temp.id,
                  temp.name,
                  &temp.age,
                  temp.department,
                  &temp.marks) == 5) {

        if (!found || temp.marks > top.marks) {
            top = temp;
            found = 1;
        }
    }

    fclose(fp);

    if (found) {
        printf("\nTop Student\n");
        printf("ID: %d\n", top.id);
        printf("Name: %s\n", top.name);
        printf("Age: %d\n", top.age);
        printf("Department: %s\n", top.department);
        printf("Marks: %.2lf\n", top.marks);
    } else {
        printf("No students found.\n");
    }
}