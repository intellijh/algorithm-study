#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int T, n, m, t, s, g, h, a, b, d, dist[2004], temp;
vector<pair<int, int>> adj[2004];
vector<int> x;

void dijkstra() {
    priority_queue<pair<int ,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while (pq.size()) {
        int here_cost = pq.top().first;
        int u = pq.top().second; pq.pop();

        if (here_cost != dist[u]) continue;

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

    cin >> T;
    while (T--) {
        cin >> n >> m >> t;
        cin >> s >> g >> h;

        for (int i = 0; i < 2004; i++) adj[i].clear();
        x.clear();
        fill(dist, dist + 2004, INF);
        dist[s] = 0;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> d;
            d *= 2;

            if (a == g && b == h) d--;
            else if (a == h && b == g) d--;
            adj[a].push_back({d, b});
            adj[b].push_back({d, a});
        }
        for (int i = 0; i < t; i++) {
            cin >> temp;
            x.push_back(temp);
        }
        sort(x.begin(), x.end());
    
        dijkstra();
        for (int i = 0; i < t; i++) {
            int xx = x[i];
            if (dist[xx] != INF && dist[xx] % 2 == 1) cout << xx << " ";
        }
        cout << '\n';
    }

    return 0;
}