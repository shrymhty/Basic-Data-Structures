//finding factorial of a number using principle of mathematical induction

#include<stdio.h>

int fact(int n)
{
    //base case
    if(n==0)
    {
        return 1;
    }
    int sans=fact(n-1); //assumption and recursive case
    int ans =n*sans; //calculation
    return ans;
}

int main()
{
    printf("%d",fact(4));
    return 0;
}