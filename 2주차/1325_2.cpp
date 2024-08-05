#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, mx;
int visited[10004], dp[10004];
vector<int> v[10004], ret;

int dfs(int idx) {
    visited[idx] = 1;
    int ret = 1;
    for (int i : v[idx]) {
        if (visited[i]) continue;
        ret += dfs(i);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> a >> b;
        v[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        fill(&visited[0], &visited[0] + 10004, 0);
        dp[i] = dfs(i);
        mx = max(mx, dp[i]);
    }
    
    for (int i = 1; i <= N; i++) {
        if (dp[i] == mx) cout << i << " ";
    }
    return 0;
}