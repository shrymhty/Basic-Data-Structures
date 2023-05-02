#include <stdio.h>
int main()
{
    int arr[5];
    int *b=arr;
    int i;
    int temp;
    for(i=0;i<5;i++)
    {
        printf("Enter the [%d] element: ",i);
        scanf("%d",&*(arr+i));
    }
    for (int i = 0; i <5; i++) 
    {     
        for (int j = i+1; j <5; j++)
        {     
            if(b[i] > b[j]) 
            {    
                temp = b[i];    
                b[i] = b[j];    
                b[j] = temp;    
            }
        }
    }     
    printf("The array in ascneding order: \n");
    for(i=0;i<5;i++)
    {
        printf("%d ",*(b+i));
    }
    float sum=0;
    for(i=0;i<5;i++)
    {
        sum=sum+*(b+i);
    }
    printf("\nThe average of the elements of the given array is %f",(sum/5));
}