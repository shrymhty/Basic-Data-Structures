#include<stdio.h>
#include<stdlib.h>
struct myArray
{
    int total_size;//memory to be reserved
    int used_size;//memory to be used
    int *ptr;

};

void createArray(struct myArray *a,int tsize, int usize)
{
    a->total_size=tsize;
    a->used_size=usize;
    a->ptr=(int *)malloc(sizeof(int)*tsize);

}

void show(struct myArray *a)
{
    for(int i=0;i<a->used_size;i++)
    {
        printf("%d ",*(a->ptr+i));
    }
}

void setVal(struct myArray *a)
{
    for(int i=0;i<a->used_size;i++)
    {
        scanf("%d ",&*(a->ptr+i));
    }
}


int main()
{
    struct myArray marks;
    createArray(&marks,100,10);
    setVal(&marks);
    show(&marks);
    return 0;
}