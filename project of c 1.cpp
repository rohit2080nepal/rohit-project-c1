#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[50];
    int roll_no;
    char department[50];
};
//function to add student
void add_student(struct student s) {
	
    printf("Enter student name: ");
    scanf("%s",s.name);
    printf("Enter student roll number: ");
    scanf("%d",&s.roll_no);
    printf("Enter department: ");
    scanf("%s",&s.department);
    FILE *fp = fopen("file.txt","a");
    fprintf(fp,"%s %d %s\n", s.name, s.roll_no, s.department);
	fclose(fp);
}

void print_student(const struct student s) {
    printf("%s\t %d \t\t %s\t\n", s.name,s.roll_no,s.department);
}
//function to display student
void display_students() {
    struct student s;
    FILE *read_fp = fopen("file.txt", "r");
    if (read_fp == NULL) {
        printf("No students found\n");
    } else {
    	 printf("----------------------------------");
     printf("\nNAME\tROLL-NUM\tDEPARTMENT\t\n");
     printf("----------------------------------\n");
        while (fscanf(read_fp, "%s %d %s", s.name, &s.roll_no, &s.department) != EOF) {
            print_student(s);
        }
         printf("----------------------------------\n");
        fclose(read_fp);
    }
}
//function to delete student by roll no.

void delete_student(int roll_no) {
    struct student s;
    FILE *read_fp = fopen("file.txt", "r");
    FILE *temp_fp = fopen("temp.txt", "w");
    if (read_fp == NULL || temp_fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    int found = 0; // f    lag to track if the student was found and deleted

    while (fscanf(read_fp, "%s %d %s", s.name, &s.roll_no, s.department) != EOF) {
        if (s.roll_no != roll_no) {
            fprintf(temp_fp, "%s %d %s\n", s.name, s.roll_no, s.department);
        } else {
            found = 1; // Student found and deleted
        }
    }

    fclose(read_fp);
    fclose(temp_fp);

    // Remove the original file and rename the temporary file
    if (found) {
        remove("file.txt");
        rename("temp.txt", "file.txt");
        printf("Student with roll number %d deleted successfully.\n", roll_no);
    } else {
        remove("temp.txt"); // delete temp file if no student was deleted
        printf("Student with roll number %d not found.\n", roll_no);
    }
}
// function to update student by roll no.

void update_student(int roll_no) {
    struct student s;
    FILE *read_fp = fopen("file.txt", "r");
    FILE *temp_fp = fopen("temp.txt", "w");
    if (read_fp == NULL || temp_fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    int found = 0; // Flag to track if the student was found and updated

    while (fscanf(read_fp, "%s %d %s", s.name, &s.roll_no, s.department) != EOF) {
        if (s.roll_no == roll_no) {
            found = 1; // Student found
            printf("Enter updated student name: ");
            scanf("%s", s.name);
             printf("Enter updated student roll no.: ");
            scanf("%d",&s.roll_no);
            printf("Enter updated student department: ");
            scanf("%s", s.department);
        }
        fprintf(temp_fp, "%s %d %s\n", s.name, s.roll_no, s.department);
    }

    fclose(read_fp);
    fclose(temp_fp);

    // Remove the original file and rename the temporary file
    if (found) {
        remove("file.txt");
        rename("temp.txt", "file.txt");
        printf("Student with roll number %d updated successfully.\n", roll_no);
    } else {
        remove("temp.txt"); // delete temp file if no student was updated
        printf("Student with roll number %d not found.\n", roll_no);
    }
}
//search room no. 
void search_room(){
    int n;
     printf("----------------------------------\n");
        printf("1. Maths\n");
        printf("2. Physics\n");
        printf("3. Chemistry\n");
        printf("4. computer\n");
        printf("5. Drawing\n");
        printf("6. Basic electrical engineering\n");
         printf("----------------------------------\n");
        printf("Enter the subject no. you want to study ");
        scanf("%d",&n);
        
        switch (n)
        {
        case 1:
            printf("Go to room no. 101 to study maths\n");
            break;
           case 2:
            printf("Go to room no. 103 to study physics\n");
            break;
        
           case 3:
            printf("Go to room no. 104 to study chemistry\n");
            break;
        
           case 4:
            printf("Go to room no. 205 to study computer\n");
            break;
        
           case 5:
            printf("Go to room no. 201 to drawing\n");
            break;
        
           case 6:
            printf("Go to room no. 302 to study Basic electrical engineering\n");
            break;
        default:
        printf("Please enter the valid subject no.\n");
            break;
        }
    
}
//search student by roll no.
void search_student(int roll_no) {
    struct student s;
    FILE *read_fp = fopen("file.txt", "r");
    if (read_fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    int found = 0; // Flag to track if the student was found
    while (fscanf(read_fp, "%s %d %s", s.name, &s.roll_no, s.department) != EOF) {
        if (s.roll_no == roll_no) {
            found = 1; // Student found
            printf("Student found:\n");
             printf("----------------------------------");
             printf("\nNAME\tROLL-NUM\tDEPARTMENT\t\n");
              printf("----------------------------------\n");
            print_student(s);
             printf("----------------------------------\n");
            break;
        }
    }

    fclose(read_fp);

    if (!found) {
        printf("Student with roll number %d not found.\n", roll_no);
    }
}

int main() {
    int choice;
    struct student s;

    while (1) {
    	 printf("==========================================");
        printf("\n\tStudent Management System\n");
         printf("==========================================\n");
	    printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Delete Student\n");
        printf("4. Update Student\n");
        printf("5. Search room number\n");
        printf("6. search student\n");
        printf("7. Exit\n");
         printf("------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student(s);
                break;
            case 2:
                display_students();
                break;

            case 3:
                printf("Enter roll number to delete: ");
                int del_roll_no;
                scanf("%d", &del_roll_no);
                delete_student(del_roll_no);
                break;

            case 4:
                printf("Enter roll number to update: ");
                int update_roll_no;
                scanf("%d", &update_roll_no);
                update_student(update_roll_no);
                break;
            case 5:
            search_room();
            break;

             case 6:
                printf("Enter roll number to search: ");
                int search_roll_no;
                scanf("%d", &search_roll_no);
                search_student(search_roll_no);
                break;

            case 7:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    }

    return 0;
}