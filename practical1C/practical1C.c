#include <stdio.h>
#include<stdlib.h>
struct Student {
    int rollNo;
    char name[50];
    int age;
    float avgMarks;
};
void bubbleSort(struct Student s[], int n) {
    int i, j;
    struct Student temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (s[j].avgMarks < s[j + 1].avgMarks) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}
int main() {
    int n, i;
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct Student s[n];
    for (i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &s[i].rollNo);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Age: ");
        scanf("%d", &s[i].age);
        printf("Average Marks: ");
        scanf("%f", &s[i].avgMarks);
    }
    bubbleSort(s, n);
    printf("\n Sorted Students by Average Marks \n");
    printf("RollNo\tName\tAge\tAvgMarks\n");
    for (i = 0; i < n; i++) {
        printf("%d \t %s\t%d\t%.2f\n", s[i].rollNo, s[i].name, s[i].age, s[i].avgMarks);
    }
    return 0;
}
