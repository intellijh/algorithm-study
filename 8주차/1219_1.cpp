#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = -1e18;
int n, m, s, e, a, b, c;
ll dist[54], money[54];
vector<pair<int, int>> adj[54];
queue<int> q;
bool visited[54];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> s >> e >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    for (int i = 0; i < n; i++) {
        cin >> money[i];
    }

    fill(dist, dist + 54, INF);
    dist[s] = money[s];
    for (int i = 0; i < n; i++) {
        for (int here = 0; here < n; here++) {
            for (auto there : adj[here]) {
                int d = there.second;
                int to = there.first;

                if (dist[here] != INF && dist[here] - d + money[to] > dist[to]) {
                    if (i == n - 1) q.push(to);
                    dist[to] = dist[here] - d + money[to];
                }
            }
        }
    }

    bool flag = false;
    while (q.size()) {
        int temp = q.front(); q.pop();
        for (auto there : adj[temp]) {
            if (there.first == e) {
                flag = true;
                break;
            }
            if (!visited[there.first]) {
                visited[there.first] = 1;
                q.push(there.first);
            }
        }
        if (flag) break;
    }

    if (dist[e] == INF) cout << "gg" << '\n';
    else if (flag) cout << "Gee" << '\n';
    else cout << dist[e] << '\n';

    return 0;
} 