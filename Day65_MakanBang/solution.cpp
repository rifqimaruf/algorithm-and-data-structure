#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // N = Jumlah Vertex
    // M = Jumlah Edge
    // S = index vertex sumber
    // T = index vertex tujuan
    int N, M, S, T;
    cin >> N >> M >> S >> T;

    vector<vector<int>> adj(N);

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

   
    vector<bool> visited(N, false);
    vector<int> distance(N, -1); 

    queue<int> q;
    q.push(S);
    visited[S] = true;
    distance[S] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i = 0; i < adj[current].size(); ++i) {
            int neighbor = adj[current][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                distance[neighbor] = distance[current] + 1;
                // cout << neighbor;
                q.push(neighbor);
            }
        }
    }

    cout << distance[T] << endl;

    return 0;
}
