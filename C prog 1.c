#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition for subject  

struct subject {
    char *subject_name;
    float grade;
    struct subject *next;
};

// Structure definition for student  

struct student {
    char *name;
    struct subject *subjects;
};

void add_subject(struct student *student1);
void display_subject_statistics(struct student *student1);
void free_memory(struct student *student1);

int main() {
    struct student student1;
    char studentName[50];
    
    printf("Enter student name: ");
    fgets(studentName, 50, stdin);
    studentName[strcspn(studentName, "\n")] = 0;
    
    student1.name = malloc(strlen(studentName) + 1);
    strcpy(student1.name, studentName);
    student1.subjects = NULL;

    int subjectsToAdd = 0;
    printf("How many subjects to add? ");
    scanf("%d", &subjectsToAdd);
    getchar();

    for (int i = 0; i < subjectsToAdd; i++) {
        add_subject(&student1);
    }

    display_subject_statistics(&student1);

    free_memory(&student1);

    return 0;
}

void add_subject(struct student *student1) {
    char subjectName[50];
    float grade;
    struct subject *newSubject = malloc(sizeof(struct subject));
    struct subject *current = student1->subjects;

    printf("Enter subject name: ");
    fgets(subjectName, 50, stdin);
    subjectName[strcspn(subjectName, "\n")] = 0;
    newSubject->subject_name = malloc(strlen(subjectName) + 1);
    strcpy(newSubject->subject_name, subjectName);

    printf("Enter subject grade: ");
    scanf("%f", &grade);
    getchar();

    newSubject->grade = grade;
    newSubject->next = NULL;

    if (current == NULL) {
        student1->subjects = newSubject;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newSubject;
    }
}

void display_subject_statistics(struct student *student1) {
    struct subject *current = student1->subjects;
    float totalGrade = 0;
    float highestGrade = -1;
    char *highestGradeSubject = NULL;
    int count = 0;

    while (current != NULL) {
        totalGrade += current->grade;
        if (current->grade > highestGrade) {
            highestGrade = current->grade;
            highestGradeSubject = current->subject_name;
        }
        current = current->next;
        count++;
    }

    if (count > 0) {
        printf("Average Grade: %.2f\n", totalGrade / count);
        printf("Highest Grade: %.2f in %s\n", highestGrade, highestGradeSubject);
    } else {
        printf("No subjects added.\n");
    }
}

void free_memory(struct student *student1) {
    struct subject *current = student1->subjects;
    struct subject *next;

    while (current != NULL) {
        next = current->next;
        free(current->subject_name);
        free(current);
        current = next;
    }

    free(student1->name);
}
