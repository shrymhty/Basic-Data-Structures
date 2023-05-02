#include<stdio.h>
#include <limits.h>
struct book
{
    int bookno;
    char title[20];
    float price;
};
int display(struct book b1[],int num)
{
    int max;
    int highest=b1[0].price;
    for(int j=0;j<num;j++)
    {
        if(b1[j].price>highest)
        {
            highest=b1[j].price;
            max=j;
        }
    }
    printf("Book details: \n");
    printf("BOOK NO.\tTitle\t\tPRICE\n");
    printf("%d\t%s\t\t%5.2f",b1[max].bookno,b1[max].title,b1[max].price);
}
int main()
{
    int n;
    printf("enter the number of books: ");
    scanf("%d",&n);
    struct book b[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter book no: ");
        scanf("%d",&b[i].bookno);
        printf("Enter book name: ");
        scanf("%s", b[i].title);
        printf("Enter the price of the book: ");
        scanf("%f",&b[i].price);
    }
    display(b,n);
    return 0;    
}
