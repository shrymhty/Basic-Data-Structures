#include<stdio.h>
#include<stdlib.h>

struct node
{
    char name[50];
    int empno;
    char sex;
    float sal;
    struct node *next;
};

void inputInfo(struct node *head, int n)
{
    int i=1;
    printf("\nEnter the info of %d employee:\n ",i);
    scanf("Enter the name: ");
    scanf("%s",head->name);
    printf("Enter the employee number: ");
    scanf("%d",&head->empno);
    printf("Enter the sex[M/F]: ");
    getchar();
    scanf("%c",&head->sex);
    printf("Enter the salary: ");
    scanf("%f",&head->sal);
    head->next=NULL;
    struct node *temp=head;
    while(i<n)
    {
        i++;
        temp->next=(struct node*)malloc(sizeof(struct node));
        if(temp->next==NULL)
        {
            printf("Out of memory space");
            exit(0);
        }
        temp=temp->next;
        printf("\nEnter the info of %d employee: \n",i);
        scanf("Enter the name: ");
        scanf("%s",temp->name);
        printf("Enter the employee number: ");
        scanf("%d",&temp->empno);
        printf("Enter the sex[M/F]: ");
        getchar();
        scanf("%c",&temp->sex);
        printf("Enter the salary: ");
        scanf("%f",&temp->sal);
        temp->next=NULL;

    }
}

void display(struct node *head,int n)
{
    struct node *curr=head;
    if(curr==NULL)
    {
        printf("Out of memoery space");
        exit(0);
    }
    printf("\nThe details of %d employees: \n");
    printf("NAME\t\t\tEMPno\t\t\tSEX\tSALARY\n");
    while(curr!=NULL)
    {
        printf("%s\t\t\t%d\t\t\t%c\t%f\n",curr->name,curr->empno,curr->sex,curr->sal);
        curr=curr->next;
    }
}

int main(void)
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("Out of memory space.");
        exit(0);
    }
    int m;
    printf("Enter the number of employees: ");
    scanf("%d",&m);
    inputInfo(ptr,m);
    display(ptr,m);
    return 0;
}