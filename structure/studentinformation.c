#include <stdio.h>
struct student
{
    int rollno;
    char name[10];
    int age;
    float cgpa;
};
//inputting  the data
void readData()
{
    
}
int main()
{
    struct student stu[5];
    //printing the information inputted
    printf("\nStudent Information\n");
    printf("STUDENT NAME\tROLL NO\tAGE\tCGPA\n");
    for(int j=0;j<5;j++)
    {
        printf("%s\t\t%d\t%d\t%.2f\n",stu[j].name,stu[j].rollno,stu[j].age,stu[j].cgpa);
    }
    return 0;
}