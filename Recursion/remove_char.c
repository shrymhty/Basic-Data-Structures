#include<stdio.h>

int length(char input[])
{
    if(input[0]=='\0'){
        return 0;
    }
    return 1 + length(input+1);;
}

void removeA(char input[],char ch)
{
   if(input[0]=='\0')
   {
    return ;
   }
   if(input[0]!= 's')
   {
    removeA(input + 1, ch);
   }
   else
   {
      for(int i=0;input[i]!='\0';i++)
      {
        input[i] = input[i+1];
      }
      removeA(input,ch);
   }
}

int main()
{
  char input[100];
  scanf("%s",input);
  int l = length(input);
  printf("length: %d",l);
  printf("\n%s\n",input);

  removeA(input,'s');

  printf("%d\n",length(input));
  printf("%s",input);
  return 0;
}
