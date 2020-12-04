#include<stdio.h>
#include<stdlib.h>

#define MAX 100

#define initial 1
#define waiting 2
#define visited 3

int n;

int adj[MAX][MAX];

int state[MAX];

int label[MAX];

int vertices;


void create_graph ();

void BF_Traversal ();

void BFS (int v, int component_Num);


int queue[MAX], front = -1, rear = -1;

void insert_queue (int vertex);

int delete_queue ();

int isEmpty_queue ();


int
main ()
{

int testcase;

scanf ("%d ", &testcase);

for (int i = 0; i < testcase; i++)

    {

create_graph ();

BF_Traversal ();

int l = label[0];

printf ("%d ", 0 + 1);

for (int i = 1; i < vertices; i++)

    {

if (l == label[i])

continue;

printf ("%d ", i + 1);


l = label[i];

}

printf ("\n");

}




}



void
BF_Traversal ()
{

int v, components = 0;


for (v = 0; v < n; v++)

state[v] = initial;


components++;

BFS (0, components);


for (v = 0; v < n; v++)

    {

if (state[v] == initial)

    {

components++;

BFS (v, components);

}

}

printf ("%d\n", components);


}



void
BFS (int v, int component_Num)
{

int i;


insert_queue (v);

state[v] = waiting;


while (!isEmpty_queue ())

    {

v = delete_queue ();

state[v] = visited;

label[v] = component_Num;



for (i = 0; i < n; i++)

    {

if (adj[v][i] == 1 && state[i] == initial)

        {
insert_queue (i);

state[i] = waiting;

}

}

}

}



void
insert_queue (int vertex)
{
if (rear == MAX - 1)
printf ("Queue Overflow\n");

  else
    {

if (front == -1)

front = 0;

rear = rear + 1;

queue[rear] = vertex;

}

}



int
isEmpty_queue ()
{

if (front == -1 || front > rear)

return 1;

  else

return 0;

}



int
delete_queue ()
{

int del_item;

if (front == -1 || front > rear)

    {

printf ("\nQueue Underflow\n");

exit (1);

}
del_item = queue[front];
front = front + 1;
return del_item;
}



void
create_graph ()
{

int i, origin, destin;
scanf ("%d", &n);
vertices = n;
for (int i = 0; i < n; i++)
    {
for (int j = 0; j < n; j++)
    {
scanf ("%d", &adj[i][j]);
}
}
}
