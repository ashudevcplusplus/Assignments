#include <stdio.h>

int main()
{
   int size;
   scanf ("%d", &size);

   int matrix[size][size];


   for(int i=0;i<size;i++)
{
   for(int j=0;j<size;j++)
   {
      scanf ("%d", &matrix[i][j]);
   }
}
int row_sum[size];
int col_sum[size];
int k=0;
int sum=0;

   for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {

            sum = sum + matrix[i][j];
        }
            printf("%d ",sum);
            row_sum[k]=sum;
            k++;
            sum=0;
   }
   printf("\n");
   k=0;

      for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {

            sum = sum + matrix[j][i];
        }
            printf("%d ",sum);
            col_sum[k]=sum;
            k++;
            sum=0;
   }
   int w,x;

      for ( w = 0; w < size; w++) {
        for ( x = 0; x < size; x ++) {

            if(row_sum[w]==col_sum[x]){
                printf("\n");
                printf("Row: %d", w+1);
                printf("\n");
                printf("Col: %d", x+1);
                printf("\n");
                printf("==========");
            }
            else {
                continue;
            }

        }}

           


return 0;
}
