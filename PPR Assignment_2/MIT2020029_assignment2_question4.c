#include <stdio.h>



int remove_Duplicates(int arr[], int n)
{

    if (n==0 || n==1)
        return n;

    int temp[n];


    int j = 0;
    for (int i=0; i<n-1; i++)


        if (arr[i] != arr[i+1])
            temp[j++] = arr[i];


    temp[j++] = arr[n-1];


    for (int i=0; i<j; i++)
        arr[i] = temp[i];

    return j;
}

int main()
{
   int size;
   scanf ("%d", &size);
   int n;
   n=size;
   int matrix[size][size];


   for(int i=0;i<n;i++)
{
   for(int j=0;j<n;j++)
   {
      scanf ("%d", &matrix[i][j]);
   }
}




  int arr[size];

  int j=0;
  int temp;

printf("Along Rows : \n");
for (int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
    arr[j]=matrix[i][j];
}


	for (int k = 0; k < size; k++)
	{
		for (int l = k + 1; l < size; l++)
		{
			if(arr[k] > arr[l])
			{
				temp = arr[k];
				arr[k] = arr[l];
				arr[l] = temp;
			}

		}
    }
       //arr is now sorted
       int new_size= remove_Duplicates(arr, n);

    for(int j=0;j<new_size;j++)
        {
        printf("%d ", arr[j]);
        }
        printf("\n");
}

printf("Along Columns : \n");
for (int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
    arr[j]=matrix[j][i];
}


	for (int k = 0; k < size; k++)
	{
		for (int l = k + 1; l < size; l++)
		{
			if(arr[k] > arr[l])
			{
				temp = arr[k];
				arr[k] = arr[l];
				arr[l] = temp;
			}

		}
    }
       //arr is now sorted
       int new_size= remove_Duplicates(arr, n);

    for(int j=0;j<new_size;j++)
        {
        printf("%d ", arr[j]);
        }
        printf("\n");
}


printf("Matrix : \n");
int new1dsize,k;
new1dsize = size *size;
int arr2d[new1dsize];


for (int i=0;i<(n*n);i++){
    arr2d[i]=0;
}


k=0;


for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
arr2d[k]=matrix[i][j];
k++;
}
}




	for (int k = 0; k < size*size; k++)
	{
		for (int l = k + 1; l < size*size; l++)
		{
			if(arr2d[k] > arr2d[l])
			{
				temp = arr2d[k];
				arr2d[k] = arr2d[l];
				arr2d[l] = temp;
			}

		}
    }
       //arr is now sorted
       int new_size= remove_Duplicates(arr2d, n*n);

    for(int j=0;j<new_size;j++)
        {
        printf("%d ", arr2d[j]);
        }
        printf("\n");

     return 0;
}
