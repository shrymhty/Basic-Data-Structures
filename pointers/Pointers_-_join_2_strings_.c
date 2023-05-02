#include <stdio.h>

int main()
{
    char aa[100], bb[100], cc[100], dd[100], ee[100];

    printf("\nEnter the first string: ");
    scanf("%s", aa);   // inputting first string

    printf("\nEnter the second string: ");
    scanf("%s", bb);   // inputting second string
    
    printf("\nEnter the third string: ");
    scanf("%s", cc);   // inputting third string
    
    printf("\nEnter the fourth string: ");
    scanf("%s", dd);   // inputting fourth string
    
    printf("\nEnter the fifth string: ");
    scanf("%s", ee);   // inputting fifth string
    
    char *a = aa;
    char *b = bb;
    char *c = cc;
    char *d = dd;
    char *e = ee;

    // pointing to the end of the 1st string
    while(*a)   // till it doesn't point to NULL-till string is not empty
    {
        a++;    // point to the next letter of the string
    }
    while(*b)   // till second string is not empty
    {
        *a = *b;
        b++;
        a++;
    }
    while(*c)   // till third string is not empty
    {
        *a = *c;
        c++;
        a++;
    }
    while(*d)   // till fourth string is not empty
    {
        *a = *d;
        d++;
        a++;
    }
    while(*e)   // till fifth string is not empty
    {
        *a = *e;
        e++;
        a++;
    }
    *a = '\0';  // string ends with '\0'
    printf("\n\n\nThe string after concatenation is: %s ", aa);

    return 0;
}