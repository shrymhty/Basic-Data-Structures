#include<stdio.h>
typedef struct
{
    char name[10];
    int empid;
    float basesal;
    float grossal;
}employee;
void display(employee *ptr)
{
    int j;
    printf("ENPLOYEE NAME\tEMPLOYEE ID\tBASIC SALARY\tGROSS SALARY\n");
    for(j=0;j<3;j++)
    {
        (*(ptr+j)).grossal=(((*(ptr+j))).basesal)+((0.1)*((*(ptr+j)).basesal))+(((0.2)*((*(ptr+j)).basesal)));
        printf("%s\t\t",((*(ptr+j)).name));
        printf("%d\t\t",((*(ptr+j)).empid));
        printf("%5.3f\t\t",((*(ptr+j)).basesal));
        printf("%5.3f\n",((*(ptr+j)).grossal));
    }
}
int main()
{
    employee info[3];
    int i;
    for(i=0;i<3;i++)
    {
        printf("Employee %d:\n",i+1);
        printf("Enter employee name: ");
        scanf("%s",info[i].name);
        printf("Enter employee id: ");
        scanf("%d",&info[i].empid);
        printf("Enter base salary: ");
        scanf("%f",&info[i].basesal);
    }
    display(&info[0]);
    return 0;
}