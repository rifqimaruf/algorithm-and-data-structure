#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

typedef pair<long long, int> PII;

struct Edge {
    int to;
    int cost;
};

int n, m, s, t;
vector<vector<Edge>> graph, reverse_graph;

vector<long long> dijkstra(int start, const vector<vector<Edge>>& g) {
    vector<long long> dist(n + 1, LLONG_MAX);
    priority_queue<PII, vector<PII>, greater<PII>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto& e : g[u]) {
            int v = e.to;
            long long nd = d + e.cost;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }

    return dist;
}

int main() {
    cin >> n >> m >> s >> t;
    graph.assign(n + 1, {});
    reverse_graph.assign(n + 1, {});

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        reverse_graph[b].push_back({a, c}); 
    }

    vector<long long> dist_from_start = dijkstra(s, graph);
    vector<long long> dist_to_end = dijkstra(t, reverse_graph);

    long long ans = dist_from_start[t]; 

    int min_pos = n / 2;

    for (int u = 1; u <= n; ++u) {
        for (auto& e : graph[u]) {
            int v = e.to;
            long long cost = e.cost;

            if (dist_from_start[u] == LLONG_MAX || dist_to_end[v] == LLONG_MAX) continue;

            long long total_cost = dist_from_start[u] + (cost / 2) + dist_to_end[v];

            long long route_cost = dist_from_start[u] + cost + dist_to_end[v];

            if (total_cost < ans) {
                ans = total_cost;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
