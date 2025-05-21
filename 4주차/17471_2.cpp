#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, m, a[14], temp, mn = INF, cnt, comp[14];
vector<int> adj[14];
bool visited[14];

pair<int, int> dfs(int here, int color) {
    visited[here] = 1;
    pair<int, int> ret = {1, a[here]};

    for (int next : adj[here]) {
        if (visited[next]) continue;
        if (comp[next] != color) continue;
        pair<int, int> tmp = dfs(next, color);
        ret.first += tmp.first;
        ret.second += tmp.second;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> temp;
            adj[i].push_back(temp);
        }
    }

    for (int i = 1; i < (1 << n) - 1; i++) {
        fill(&comp[0], &comp[0] + 14, 0);
        fill(&visited[0], &visited[0] + 14, 0);
        int idx1 = -1, idx2 = -1;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {comp[j + 1] = 1; idx1 = j + 1;}
            else idx2 = j + 1;
        }
        pair<int, int> comp1 = dfs(idx1, 1);
        pair<int, int> comp2 = dfs(idx2, 0);

        if (comp1.first + comp2.first == n) {
            mn = min(mn, abs(comp1.second - comp2.second));
        }
    }

    if (mn == INF) cout << -1 << '\n';
    else cout << mn << '\n';

    return 0;
}