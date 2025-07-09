#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m, x, dist[1004], dist_r[1004], a, b, c, ret;
vector<pair<int, int>> adj[1004], adj_r[1004];

void dijkstra(int* dist, vector<pair<int, int>>* adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, x});
    while (pq.size()) {
        int here_cost = pq.top().first; 
        int u = pq.top().second; pq.pop();

        if (here_cost != dist[u]) {
            continue;
        }

        for (auto there : adj[u]) {
            int new_cost = here_cost + there.first;
            int v = there.second;
            if (dist[v] > new_cost) {
                dist[v] = new_cost;
                pq.push({new_cost, v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> x;

    fill(dist, dist + 1004, INF);
    fill(dist_r, dist_r + 1004, INF);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj_r[b].push_back({c, a});
    }

    dist[x] = 0;
    dist_r[x] = 0;
    dijkstra(dist, adj);
    dijkstra(dist_r, adj_r);

    for (int i = 1; i <= n; i++) {
        if (dist[i] != INF && dist_r[i] != INF) {
            ret = max(ret, dist[i] + dist_r[i]);
        }
    }
    cout << ret << '\n';
    return 0;
}