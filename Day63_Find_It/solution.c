#include <stdio.h>
#include <string.h>

#define MAX_VERTICES 101
#define MAX_EDGES 100

struct Edge {
    int to;
    int weight; 
};

struct Edge graph[MAX_VERTICES][MAX_EDGES]; 
int edge_count[MAX_VERTICES];   
int visited[MAX_VERTICES];                 
int found;                                 
int target;

void dfs(int v, int sum) {
    if (found) return; 
    if (sum == target) {
        found = 1; 
        return;
    }
    if (sum > target) return; 

    for (int i = 0; i < edge_count[v]; i++) {
        int u = graph[v][i].to;
        int w = graph[v][i].weight;
        if (!visited[u]) {
            visited[u] = 1;
            dfs(u, sum + w);
            visited[u] = 0; 
        }
    }
}

int main() {
    int T, i, j, w, max_vertex;

    scanf("%d", &T);

    while (T--) {
        memset(edge_count, 0, sizeof(edge_count));
        memset(visited, 0, sizeof(visited));
        found = 0;
        max_vertex = 0;

        while (1) {
            scanf("%d %d %d", &i, &j, &w);
            if (i == 0 && j == 0 && w == 0) break;

            graph[i][edge_count[i]].to = j;
            graph[i][edge_count[i]].weight = w;
            edge_count[i]++;
            graph[j][edge_count[j]].to = i;
            graph[j][edge_count[j]].weight = w;
            edge_count[j]++;
            if (i > max_vertex) max_vertex = i;
            if (j > max_vertex) max_vertex = j;
        }

        scanf("%d", &target);

        for (int v = 1; v <= max_vertex && !found; v++) {
            if (edge_count[v] > 0) { 
                visited[v] = 1;
                dfs(v, 0);
                visited[v] = 0;
            }
        }

        printf("%s\n", found ? "YES" : "NO");
    }

    return 0;
}