#include <bits/stdc++.h>
using namespace std;

int n, m, mx, t1, t2, cnt;
vector<int> v[10004];
vector<int> ret;
bool visited[10004];

void go(int here) {
    visited[here] = 1;

    for (int there : v[here]) {
        if (visited[there]) continue;
        cnt++;
        go(there);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> t1 >> t2;
        v[t2].push_back(t1);
    }

    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));

        cnt = 0;
        go(i);
        if (cnt > mx) {
            mx = cnt;
            ret.clear();
            ret.push_back(i);
        } else if (cnt == mx) {
            ret.push_back(i);
        } 
    }

    sort(ret.begin(), ret.end());
    for (int i : ret) cout << i << " ";

    return 0;
}