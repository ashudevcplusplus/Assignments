#include <stdio.h>
int MAXSIZE = 200;
char stack[200];
int top = -1;
char pop()
{
   char data;
   if(top != -1) {
      data = stack[top];
      top = top - 1;
      return data;
   } else
   {
      printf("Stack is empty\n");
   }
}

void push(char data) {

   if(top != MAXSIZE)
   {
      top = top + 1;
      stack[top] = data;
   } else
   {
      printf("Stack is full.\n");
   }
}

int main()
{
   int test;
   scanf("%d", &test);
   for(int k=0;k<test;k++){
   int len;
   char str1[200];
   char str2[200];
   fgets (str1, 200, stdin);
   scanf("%[^\n]%*c", str1);
   for (len = 0; str1[len] != '\0'; ++len);
   for(int i=0; i<len; i++){
       push(str1[i]);
   }

      for(int i=0; i<len; i++){
       str2[i]=pop();
   }

         for(int i=0; i<len; i++){
       printf("%c",str2[i]);


   }
   printf("\n");

   }


     return 0;
}
