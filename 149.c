#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int roll;
    float marks;
};

int main() {
    struct Student *ptr;

    // allocate memory dynamically
    ptr = (struct Student*) malloc(sizeof(struct Student));

    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input using pointer and -> operator
    printf("Enter name: ");
    scanf("%s", ptr->name);

    printf("Enter roll number: ");
    scanf("%d", &ptr->roll);

    printf("Enter marks: ");
    scanf("%f", &ptr->marks);

    // Display details
    printf("\n--- Student Details ---\n");
    printf("Name  : %s\n", ptr->name);
    printf("Roll  : %d\n", ptr->roll);
    printf("Marks : %.2f\n", ptr->marks);

    // free allocated memory
    free(ptr);

    return 0;
}
