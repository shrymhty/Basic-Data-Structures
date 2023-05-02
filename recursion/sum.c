#include<stdio.h>  
int sum(int num)  
{  
    if(num)  
        return(num+sum(num-1));  
    else  
        return 0;  
}  
int main()  
{  
    int num = 10;  
    printf("Sum : %d ",sum(num));  
    return 0;  
} 