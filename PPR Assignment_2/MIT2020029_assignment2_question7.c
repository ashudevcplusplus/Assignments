#include <stdio.h>



int main()
{
   int test,j;
   scanf ("%d", &test);

   for (j = 0; j < test; j++)
   {
   char str[200];
   int i,len;

   scanf("%s", str);
   for (len = 0; str[len] != '\0'; ++len);
    int k = len-1;

    char new_str[200];
    for (int i = 0; i < len; i++) {
      new_str[i]= str[k--];
    }
    new_str[len]= '\0';
    char *x,*y;
    x=str;
    y=new_str;
    int bit = 0;
    while (*x != '\0' || *y != '\0') {
        if (*x == *y) {
            x++;
            y++;
        }

        else if ((*x == '\0' && *y != '\0')
                 || (*x != '\0' && *y == '\0')
                 || *x != *y) {
            bit = 1;
            printf("No\n");
            break;
        }
    }
    if (bit == 0) {
        printf("Yes\n");
    }

   }
     return 0;
}
