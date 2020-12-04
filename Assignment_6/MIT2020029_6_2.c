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
    for(int i=0; i<10;i++)
    {
        parent[i]=-1;
        make_set(i);
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

    printf("After performing below operations -\nunion_sets(1,5);\nunion_sets(3,7);\nunion_sets(1,4);\nunion_sets(5,7);\nunion_sets(0,8);\nunion_sets(6,9);\nunion_sets(3,9);\n");


    printf("Disjoint set parent array - ");
    for(int i=0; i<10;i++)
    {
    printf("%d ", parent[i]);
    }




    return 0;
}
