#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int t = 1, n, a[128][128], dist[128 * 128], temp;
vector<pair<int, int>> adj[128 * 128];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({dist[0], start});
    while (pq.size()) {
        int here_cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

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

    while (true) {
        cin >> n;
        if (n == 0) break;
        memset(a, 0, sizeof(a));

        fill(dist, dist + 128 * 128, INF);
        for (int i = 0; i < 128 * 128; i++) adj[i].clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        dist[0] = a[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                    adj[i * n + j].push_back({a[ny][nx], ny * n + nx});
                }
            }
        }

        dijkstra(0);
        cout << "Problem " << t << ": " << dist[(n - 1) * n + n - 1] << '\n';
        t++;
    }

    return 0;
}