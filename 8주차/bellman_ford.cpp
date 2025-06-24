#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;

ll n, m, dist[1004];
vector<pair<int, int>> adj[1004];
queue<int> q;

int main() {
    cin >> n >> m;

    fill(dist, dist + 1004, INF);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    dist[1] = 0;
    for (int i = 0; i < n; i++) {
        for (int here = 1; here <= n; here++) {
            for (auto there : adj[here]) {
                int to = there.first;
                int d = there.second;
    
                if (dist[here] != INF && dist[here] + d < dist[to]) {
                    if (i == n - 1) q.push(to);
                    dist[to] = dist[here] + d;
                }
            }
        }
    }

    if (q.size()) cout << -1 << '\n';
    else {
        for (int i = 1; i <= n; i++) {
            cout << (dist[i] == INF ? -1 : dist[i])  << '\n';
        }
    }

    return 0;
}