#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int t, n, a[128][128], dist[128][128];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while (++t) {
        cin >> n;
        if (n == 0) break;

        fill(&a[0][0], &a[0][0] + 128 * 128, 0);
        fill(&dist[0][0], &dist[0][0] + 128 * 128, INF);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        dist[0][0] = a[0][0];

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({dist[0][0], 0});
        while (pq.size()) {
            int here_cost = pq.top().first;
            int y = pq.top().second / n;
            int x = pq.top().second % n;
            pq.pop();

            if (here_cost != dist[y][x]) continue;

            for (int k = 0; k < 4; k++) {
                int ny = y + dy[k];
                int nx = x + dx[k];
                if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                int new_cost = here_cost + a[ny][nx];

                if (dist[ny][nx] > new_cost) {
                    dist[ny][nx] = new_cost;
                    pq.push({new_cost, ny * n + nx});
                }
            }
        }
        cout << "Problem " << t << ": " << dist[n - 1][n - 1] << '\n';
    }

    return 0;
}