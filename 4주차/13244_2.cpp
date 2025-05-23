#include <bits/stdc++.h>
using namespace std;

int t, n, m, a, b, cnt;
vector<int> adj[1004], temp[1004];
bool visited[1004];

void dfs(int idx) {
    visited[idx] = 1;
    for (int i : adj[idx]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
                cnt++;
            }
        }
        
        if (cnt == 1 && m == n - 1) cout << "tree" << '\n';
        else cout << "graph" << '\n'; 

        //초기화
        cnt = 0;
        fill(&visited[0], &visited[0] + 1004, 0);
        for (int i = 1; i <= n; i++) adj[i].clear();
    }

    return 0;
}