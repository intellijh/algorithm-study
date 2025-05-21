#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, m, a[14], temp, mn = INF, cnt;
vector<int> adj[14], v;
bool visited[14];

int dfs(int here, int color) {
    int ret = a[here];
    visited[here] = 1;

    for (int next : adj[here]) {
        bool isHere = color & (1 << (here - 1));
        bool isNext = color & (1 << (next - 1));
        if (visited[next] || (isHere != isNext)) continue;
        ret += dfs(next, color);
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
        cnt = 0;
        v.clear();
        fill(&visited[0], &visited[0] + 14, 0);
        for (int j = 1; j <= n; j++) {
            if (!visited[j]) {
                v.push_back(dfs(j, i));
                cnt++;
            }
        }
        
        if (cnt == 2) {
            mn = min(mn, abs(v[0] - v[1]));
        }
    }

    if (mn == INF) cout << -1 << '\n';
    else cout << mn << '\n';

    return 0;
}