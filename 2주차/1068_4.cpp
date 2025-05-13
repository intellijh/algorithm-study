#include <bits/stdc++.h>
using namespace std;

int n, temp, root, t;
vector<int> adj[54];

int dfs(int here) {
    int child = 0;
    int ret = 0;
    for (int there : adj[here]) {
        if (there == t) continue;
        child++;
        ret += dfs(there);
    }
    if (child == 0) return 1;
    else return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp == -1) root = i;
        else  adj[temp].push_back(i);
    }
    cin >> t;

    if (t == root) cout << 0 << '\n';
    else cout << dfs(root) << '\n';

    return 0;
}