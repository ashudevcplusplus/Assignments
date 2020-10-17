#include <stdio.h>

int mul_by_n_minus_one(int *num, int n_minus_one , int count_digits){
    int temp=0;
    int index=0;
    int y=0;
    
    for(int i = 0; i<count_digits; i++){
        
        y=num[index]*n_minus_one+temp;
        num[index]=y%10;
        temp=y/10;
        index++;
    }
    
    
    while(temp>0){
        num[count_digits]=temp%10;
        temp=temp/10;
        count_digits++;
    }
    
    
    return count_digits;
    
    
}

int digits_in_input(int n)
{
    int count_digits;
         while (n != 0) 
    {
        n /= 10;     
        ++count_digits;
    }
    printf("%d", count_digits);
    printf("\n");
    return count_digits;
}


int main()
{   int n;
    int num[20000];
    int num_size=1;
    int count_digits;
    num[0]=1;
    int fac,temp;
    for(int i=0;i<20000;i++)
    {
        num[i]=10;
    }
    
    scanf(" %d", &fac);
    count_digits=digits_in_input(fac);
    
    if(fac==1 || fac==0)
    {
        //printf("Factorial of given no. is: 1");
    }
    
    else if(fac>1)
    {
        int i=0;
        int rem,value;
        value=fac;
        while(i<count_digits)
        {
            rem=value%10;
            num[i]=rem;
            value= value/10;
            i++;
        }
        int loop = fac - 1;
        int new_size;
        printf("Saved digits in array: ");
    for(int i=0;i<count_digits;i++)
    {
        printf("%d", num[i]);
    }
    printf("\n");
    
   // printf("loop %d count_digits %d", loop,count_digits);
    //printf("\n");
    
    new_size=count_digits;
    
    while(loop>1){
        new_size = mul_by_n_minus_one(num,loop,new_size);
        loop--;
    }
    
    printf("No. of digits in output : %d", new_size);
    printf("\n");
    
    int print;
    print=new_size;
    
    int k=new_size - 1;
    for(int i=0;i<new_size;i++)
    {   
        printf("%d", num[k]);
        k--;
    }
    
        
    }
    else 
    {
        
    }
    

    return 0;
}
