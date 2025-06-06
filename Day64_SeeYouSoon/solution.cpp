#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const long long INF = LLONG_MAX;

int minDistance(const vector<long long>& dist, const vector<bool>& visited, int V) {
    long long minVal = INF;
    int minIndex = -1;

    for (int v = 0; v < V; ++v) {
        if (!visited[v] && dist[v] <= minVal) {
            minVal = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printPath(int dest, const vector<int>& parent) {
    if (parent[dest] == -1) {
        cout << dest << endl;
        return;
    }
    vector<int> path;
    int crawl = dest;
    while (crawl != -1) {
        path.push_back(crawl);
        crawl = parent[crawl];
    }
    for (int i = path.size() - 1; i >= 0; --i) {
        cout << path[i];
        if (i > 0) cout << " - ";
    }
    cout << endl;
}

void dijkstra(int src, const vector<vector<long long>>& adjMatrix, int V) {
    vector<long long> dist(V, INF);
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);

    dist[src] = 0;

    for (int count = 0; count < V - 1; ++count) {
        int u = minDistance(dist, visited, V);
        if (u == -1) break; 
        visited[u] = true;

        for (int v = 0; v < V; ++v) {
            if (!visited[v] && adjMatrix[u][v] && dist[u] != INF &&
                dist[u] + adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adjMatrix[u][v];
                parent[v] = u;
            }
        }
    }

    for (int i = 0; i < V; ++i) {
        if (i == src) continue;
        cout << "---From " << src << " to " << i << "---" << endl;
        if (dist[i] == INF) {
            cout << "No path found" << endl;
        } else {
            printPath(i, parent);
        }
    }
}

int main() {
    int A, B;
    cin >> A >> B;

    vector<vector<long long>> adjMatrix(A, vector<long long>(A, 0));

    for (int i = 0; i < B; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w; 
    }

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int S;
        cin >> S;
        if (S < 0 || S >= A) {
            cout << "Invalid starting point" << endl;
        } else {
            dijkstra(S, adjMatrix, A);
        }
    }

    return 0;
}
