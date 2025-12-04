#include <stdio.h>

struct Employee {
    int id;
    char name[30];
    float salary;
};

int main() {
    struct Employee emp, emp_read;
    FILE *fp;

    // ---- INPUT EMPLOYEE DATA ----
    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);

    printf("Enter Employee Name: ");
    scanf("%s", emp.name);

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    // ---- WRITE TO BINARY FILE ----
    fp = fopen("employee.dat", "wb");   // wb = write binary
    if (!fp) {
        printf("Error opening file!\n");
        return 1;
    }

    fwrite(&emp, sizeof(struct Employee), 1, fp);
    fclose(fp);

    printf("\nData written to file successfully!\n");

    // ---- READ FROM BINARY FILE ----
    fp = fopen("employee.dat", "rb");   // rb = read binary
    if (!fp) {
        printf("Error opening file!\n");
        return 1;
    }

    fread(&emp_read, sizeof(struct Employee), 1, fp);
    fclose(fp);

    // ---- DISPLAY DATA ----
    printf("\n--- Employee Details Read From File ---\n");
    printf("ID: %d\n", emp_read.id);
    printf("Name: %s\n", emp_read.name);
    printf("Salary: %.2f\n", emp_read.salary);

    return 0;
}
