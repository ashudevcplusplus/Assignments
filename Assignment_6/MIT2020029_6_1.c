#include <stdio.h>
int parent[10], rank[10], size[10];

void make_set(int v)
{
    parent[v] = v;
}
int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}
int main()
{

    printf("Initially calling make set to insert elements (0 to 9) in disjoint set\n");
    for(int i=0; i<10;i++)
    {
        parent[i]=-1;
        make_set(i);
        printf("make_set(%d); called\n",i);
    }
        printf("Initially disjoint set parent array which contain elements from (0 to 9) - ");
    for(int i=0; i<10;i++)
    {
    printf("%d ", parent[i]);
    }
    printf("\n");

    union_sets(1,5);
    union_sets(3,7);
    union_sets(1,4);
    union_sets(5,7);
    union_sets(0,8);
    union_sets(6,9);
    union_sets(3,9);

    printf("Then we performing below operations -\nunion_sets(1,5);\nunion_sets(3,7);\nunion_sets(1,4);\nunion_sets(5,7);\nunion_sets(0,8);\nunion_sets(6,9);\nunion_sets(3,9);\n");



    printf("Now calling find_set for finding each element from (0 to 9) in disjoint set\n");
        for(int i=0; i<10;i++)
    {
        printf("find_set(%d); which gives output as %d \n", i, find_set(i));
    }



    printf("Disjoint set parent array - ");
    for(int i=0; i<10;i++)
    {
    printf("%d ", parent[i]);
    }
    return 0;
}
/*
Your Output (stdout)
Initially calling make set to insert elements (0 to 9) in disjoint set
make_set(0); called
make_set(1); called
make_set(2); called
make_set(3); called
make_set(4); called
make_set(5); called
make_set(6); called
make_set(7); called
make_set(8); called
make_set(9); called
Initially disjoint set parent array which contain elements from (0 to 9) - 0 1 2 3 4 5 6 7 8 9
Then we performing below operations -
union_sets(1,5);
union_sets(3,7);
union_sets(1,4);
union_sets(5,7);
union_sets(0,8);
union_sets(6,9);
union_sets(3,9);
Now calling find_set for finding each element from (0 to 9) in disjoint set
find_set(0); which gives output as 0
find_set(1); which gives output as 1
find_set(2); which gives output as 2
find_set(3); which gives output as 1
find_set(4); which gives output as 1
find_set(5); which gives output as 1
find_set(6); which gives output as 1
find_set(7); which gives output as 1
find_set(8); which gives output as 0
find_set(9); which gives output as 1
Disjoint set parent array - 0 1 2 1 1 1 1 3 0 6
*/
