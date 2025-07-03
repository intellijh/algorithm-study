#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m, s, d, u, v, p, dist[504], adj[504][504];

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist, dist + 504, INF);
    dist[s] = 0;
    pq.push({0, s});

    while (pq.size()) {
        int here_cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist[u] != here_cost) continue;

        for (int i = 0; i < n; i++) {
            if (adj[u][i] == -1) continue;

            int new_cost = here_cost + adj[u][i];
            if (dist[i] > new_cost) {
                dist[i] = new_cost;
                pq.push({new_cost, i});
            }
        }
    }
}

void eraseEdge() {
    queue<int> q;
    q.push(d);

    while (q.size()) {
        int v = q.front(); q.pop();
        
        for (int i = 0; i < n; i++) {
            if (dist[v] == dist[i] + adj[i][v] && adj[i][v] != -1) {
                adj[i][v] = -1;
                q.push(i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        cin >> s >> d;

        memset(adj, -1, sizeof(adj));
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> p;
            adj[u][v] = p;
        }
    
        dijkstra();
        eraseEdge();
        dijkstra();
        if (dist[d] == INF) cout << -1 << '\n';
        else cout << dist[d] << '\n';
    }

    return 0;
}