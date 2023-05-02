/*Your CR (Class Representative) went for a walk in a garden. There are many trees in the
garden and each tree has an English alphabet on it. While CR was walking, he/she noticed
that all trees with vowels on it are not in good state. She/he decided to take care of them.
So, he/she asked you to tell him the count of such trees in the garden.*/

#include<stdio.h>
#include<ctype.h>

int search(char arr[],int n)
{
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(isalpha(arr[i]))
        {
            if(tolower(arr[i])=='a'||tolower(arr[i])=='e'||tolower(arr[i])=='i'||tolower(arr[i])=='o'||tolower(arr[i])=='u')
            {
                c++;
            }
        }
    }
    return c;
}

int main()
{
    char arr[60];
    printf("Enter a string sequence consisting of alpahbets: ");
    scanf("%s",arr);
    int n=sizeof(arr)/sizeof(arr[0]);
    int num=search(arr,n);
    printf("Number of vowels: %d",num);
    return 0;
}