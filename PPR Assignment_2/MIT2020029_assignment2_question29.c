#include <stdio.h>
void print_occ_string(char s[]) 
{ 
    int count = 1;
    for (int i = 0; s[i] != '\0'; i++) { 
  
     
         
        while (s[i] == s[i + 1]) { 
            i++; 
            count++; 
        }
        if(count==1){
        printf("%d%c", count, s[i]); 
        }
        else{
        printf("%d%c", count, s[i-1]);
        }
        count=1;
       
    } 
} 


int main()
{ 
   int test,j;
   scanf ("%d", &test);
  
   for (j = 0; j < test; j++)
   {
   char str[20];
   int i,len;
   scanf("%s", str); 
  
   
   for (len = 0; str[len] != '\0'; ++len);
   
    for(i=0;i<len;i++)
    {
      if(str[i]>=65&&str[i]<=90)
         str[i]=str[i]+32;
    }
   
    print_occ_string(str);
    printf("\n");
    
   }
     return 0; 
}