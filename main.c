#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "helper.h"

int main(){
    int choice;
    while(1){

        printf("========Student Management System============\n");
        printf("1-Add\n2-Delete\n3-Update\n4-Search\n5-Display records\n6-Exit\n");
        printf("Enter your choice: ");
        scanf("%1d",&choice);
        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            deleteStudent();
            break;
        case 3:
            updateStudent();
            break;
        case 4:
            searchStudent();
            break;
        case 5:
            displayStudents();
            break;
        case 6:
            exit(0);
        
        default:
            printf("Invalid choice try again:");
            break;
        }
    }

    }