#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Subject {
    char *subject_name;
    float grade;
};

struct Student {
    char *name;
    int num_subjects;
    struct Subject *subjects;
};

void populate_subjects(struct Student *student) {
    printf("Enter the number of subjects for %s: ", student->name);
    scanf("%d", &student->num_subjects);
    student->subjects = (struct Subject *)malloc(student->num_subjects * sizeof(struct Subject));

    for (int i = 0; i < student->num_subjects; i++) {
        char buffer[100];
        printf("Enter the name of subject %d: ", i + 1);
        scanf("%99s", buffer);

        student->subjects[i].subject_name = (char *)malloc(strlen(buffer) + 1);
        strcpy(student->subjects[i].subject_name, buffer);

        printf("Enter the grade for %s: ", student->subjects[i].subject_name);
        scanf("%f", &student->subjects[i].grade);
    }
}

void display_subject_statistics(struct Student *student) {
    if (student->num_subjects == 0) {
        printf("No subjects to display statistics for.\n");
        return;
    }

    float sum = 0;
    float highest_grade = 0;
    char *highest_subject = NULL;

    for (int i = 0; i < student->num_subjects; i++) {
        sum += student->subjects[i].grade;
        if (student->subjects[i].grade > highest_grade || i == 0) {
            highest_grade = student->subjects[i].grade;
            highest_subject = student->subjects[i].subject_name;
        }
    }

    float average = sum / student->num_subjects;
    printf("Average grade for %s is: %.2f\n", student->name, average);
    printf("Highest grade is in %s: %.2f\n", highest_subject, highest_grade);
}

int main() {
    struct Student student1;
    char student_name[100];

    printf("Enter the student's name: ");
    scanf("%99s", student_name);
    student1.name = (char *)malloc(strlen(student_name) + 1);
    strcpy(student1.name, student_name);

    populate_subjects(&student1);
    display_subject_statistics(&student1);

    for (int i = 0; i < student1.num_subjects; i++) {
        free(student1.subjects[i].subject_name);
    }
    free(student1.subjects);
    free(student1.name);

    return 0;
}
