#include <stdio.h>
void reverse();
int main() {
    printf("Enter a sentence: ");
    reverse();
    return 0;
}
void reverse() 
{
    char ch;
    scanf("%c", &ch);
    if (ch != '\n') 
    {
        reverse();
        printf("%c", ch);
    }
}