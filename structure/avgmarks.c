#include <stdio.h>
int i,j;
typedef struct
{
    int rollno;
    int sem;
    int sub[3];
}s;
float calculate(s *ptr)
{
    float average=(float)((*ptr).sub[0]+(*ptr).sub[1]+(*ptr).sub[2])/3.00;
    return average;
}
int main()
{
    s stu;
    printf("STUDENT DETAILS: \n");
    printf("Enter the student roll no: \n");
    scanf("%d",&stu.rollno);
    printf("Semester: \n");
    scanf("%d",&stu.sem);
    for(j=0;j<3;j++)
    {
        printf("Enter marks of Sub %d: ",j+1);
        scanf("%d",&stu.sub[j]);
    }
    printf("The average of all three subjects: %5.2f",calculate(&stu));
    return 0;
}