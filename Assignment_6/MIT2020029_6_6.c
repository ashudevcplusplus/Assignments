
#include <stdio.h>
#define MAX 10000

int disjoint_set_parent[MAX];
int count[MAX];
int size = 0;
int union_size(int u, int v){
    u = find_parent(u);
    v = find_parent(v);
    if(u == v) return 0;
    if(count[u] >= count[v])
    {
        count[u] += count[v];
        disjoint_set_parent[v] = u;
    }else{
        count[v] += count[u];
        disjoint_set_parent[u] = v;
    }
    return 1;
}
int find_parent(int u){
    if(disjoint_set_parent[u] != u){
        return find_parent(disjoint_set_parent[u]);
    }
    return u;
}
void make_set(int N){
    size = N;
    for (int i = 0; i < N; i++){
        disjoint_set_parent[i] = i;
        count[i] = 1;
    }
}



int same(int u, int v){
    return find_parent(u) == find_parent(v);
}



int main(){
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- > 0){
        int V;
        scanf("%d", &V);
        int graph[V + 1][V + 1];
        for (int i = 1; i <= V; i++){
            for (int j = 1; j <= V; j++){
                scanf("%d", &graph[i][j]);
            }
        }

        make_set(V + 1);
        int edgecount = 0;
        for (int i = 1; i <= V; i++){
            for (int j = 1; j <= V; j++){
                if(graph[i][j] == 1){
                    edgecount += union_size(i, j);
                }
            }
        }

        if(edgecount + 1 == V){
            printf("Connected\n");
        }else{
            printf("Disconnected\n");
        }
    }
    return 0;
}
