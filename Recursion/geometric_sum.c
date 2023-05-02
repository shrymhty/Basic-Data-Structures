#include<stdio.h>
#include<math.h>

double geo(int n)
{
    if(n==0)
    {
        return 1;
    }
    return geo(n-1)+(1.0/pow(2,n));
}

int main()
{
    
}