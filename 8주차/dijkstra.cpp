#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m, start;
vector<pair<int, int>> adj[20004];
vector<int> dist(20004, INF);

void dijkstra(int here) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[here] = 0;
    pq.push({0, here});

    while (pq.size()) {
        int here_cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist[u] != here_cost) continue;

        for (auto there : adj[u]) {
            int new_cost = here_cost + there.first;
            if (dist[there.second] > new_cost) {
                dist[there.second] = new_cost;
                pq.push({new_cost, there.second});
            }
        }
    }
}

int main() {
    
    cin >> n >> m >> start;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    dijkstra(start);

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << '\n';
    }

    return 0;
}