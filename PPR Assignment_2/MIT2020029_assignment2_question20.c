#include <stdio.h>
#include <stdlib.h>

 struct Node 
{
  
int data;
   
struct Node *left;
   
struct Node *right;
 
};

struct Node *head = NULL;

struct Node *tail = NULL;

 
int
listIsEmpty () 
{
  
if (head == NULL)
    return 1;
  
  else
    return 0;

}


 
struct Node *
createNode (int data) 
{
  
struct Node *temp = (struct Node *) malloc (sizeof (struct Node *));
  
temp->data = data;
  
temp->left = NULL;
  
temp->right = NULL;
  
return temp;

}


 
void
addFirst (int data) 
{
  
struct Node *temp = createNode (data);
  
if (head == NULL)
    
head = tail = temp;
  
  else
    
    {
      
temp->right = head;
      
head->left = temp;
      
head = temp;
    
}

}


 
void
printList () 
{
  
struct Node *temp = head;
  
while (temp)
    
    {
      
printf ("%d", temp->data);
      
temp = temp->right;
    
}

}


 
void
addLast (int data) 
{
  
struct Node *temp = createNode (data);
  
if (head == NULL)
    
head = tail = temp;
  
  else
    
    {
      
tail->right = temp;
      
temp->left = tail;
      
tail = temp;
    
}

}


int
removeFirst () 
{
  
int temp = head->data;
  
if (head == tail)
    
    {
      
free (head);
      
head = tail = NULL;
    
}
  
  else
    
    {
      
head = head->right;
      
free (head->left);
      
head->left = NULL;
    
}
  return temp;

}


int
removeLast () 
{
  
int temp = tail->data;
  
if (head == tail)
    
    {
      
free (head);
      
head = tail = NULL;
    
}
  
  else
    
    {
      
tail = tail->left;
      
free (tail->right);
      
tail->right = NULL;
    
}
  return temp;

}


int
peekFirst () 
{
  
return (head->data);

}


 
int
peekLast () 
{
  
return (tail->data);

}


 
slidingWindowMax (int *arr, int n, int k) 
{
  
addFirst (0);
  
for (int i = 1; i < k; i++)
    
    {
      
while (!listIsEmpty () && arr[i] >= arr[peekLast ()])
	
removeLast ();
      
addLast (i);
    
}
  for (int i = k; i < n; i++)
    
    {
      
//printing the maximum element of the previous window
	printf ("%d ", arr[peekFirst ()]);
      
if (peekFirst () == (i - k))
	
removeFirst ();
      
//removing the useless elemts before inserting the next
//element in the window
	while (!listIsEmpty () && arr[i] >= arr[peekLast ()])
	
removeLast ();
      
addLast (i);
    
}
  
printf ("%d ", arr[peekFirst ()]);

 head = NULL;
 tail = NULL;

}


 
int main () 
{
  
int test, i;
scanf ("%d", &test);
  
for (i = 0; i < test; i++)
    {
      
int size, k;
      
scanf ("%d %d", &size, &k);
      
int arr[size];
      
int j;
      
for (j = 0; j < size; j++)
	{
	    
      scanf ("%d", &arr[j]);
	
}
      
slidingWindowMax (arr, size, k);
printf("\n");
    
 
}
  
 
return 0;

}
