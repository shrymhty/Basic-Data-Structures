/*number of jumps you can take from o to n step if you can take 1,2 or 3 steps at
once*/

#include<stdio.h>

int count(int n)
{
    if(n==1||n==0)
    {
        return n;
    }
    if(n==2)
    {
        return 2;
    }
    return count(n-1)+count(n-1)+count(n-3);
}

int main()
{
    printf("%d",count(3));
    return 0;
}