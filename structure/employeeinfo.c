#include <stdio.h>
struct employee
{
    long int empid;
    char empname[10];
    float sal;
    int age;
}s;
int main()
{
    printf("Enter the following details: \n");
    printf("Enter the employee ID: ");
    scanf("%ld",&s.empid);
    printf("Enter name of the employee: ");
    scanf("%s",s.empname);
    printf("Enter base salary: ");
    scanf("%f",&s.sal);
    printf("Enter the age of each employee: ");
    scanf("%d",&s.age);
    printf("EMPLOYEE DETAILS: \n");
    printf("EMPLOYEE ID\tEMPLOYEE NAME\tAGE\tBASE SALARY\n");
    printf("%ld\t%s\t\t%d\t%5.2f\n",s.empid,s.empname,s.age,s.sal);
}