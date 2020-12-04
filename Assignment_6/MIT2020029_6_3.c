#include <stdio.h>
int parent[10], rank[10], size[10];


int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}
void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
}

void union_sets_rank(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
        {
            int temp;
            temp=a;
            a=b;
            b=temp;
        }
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
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
    union_sets_rank(1,5);
    union_sets_rank(3,7);
    union_sets_rank(1,4);
    union_sets_rank(5,7);
    union_sets_rank(0,8);
    union_sets_rank(6,9);
    union_sets_rank(3,9);

    printf("After performing below operations -\nunion_sets_by_rank(1,5);\nunion_sets_by_rank(3,7);\nunion_sets_by_rank(1,4);\nunion_sets_by_rank(5,7);\nunion_sets_by_rank(0,8);\nunion_sets_by_rank(6,9);\nunion_sets_by_rank(3,9);\n");


    printf("Disjoint set parent array - ");
    for(int i=0; i<10;i++)
    {
    printf("%d ", parent[i]);
    }




    return 0;
}
