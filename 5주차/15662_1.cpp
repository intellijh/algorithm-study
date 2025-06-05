#include <bits/stdc++.h>
using namespace std;

string a[1004];
int n, k, x, y, ret;
vector<pair<int, int>> v;
bool visited[1004];

void go(int here, int di) {
    if (visited[here]) return;
    visited[here] = 1;

    if (here != 0 ) {    
        if (a[here][6] != a[here - 1][2]) go(here - 1, -di);
    };
    
    if (here != n - 1) {
        if (a[here][2] != a[here + 1][6]) go(here + 1, -di);
    }

    if (di == 1) rotate(a[here].rbegin(), a[here].rbegin() + 1, a[here].rend());
    else if (di == -1) rotate(a[here].begin(), a[here].begin() + 1, a[here].end());
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> x >> y; x--;
        v.push_back({x, y});
    }

    for (int i = 0; i < k; i++) {
        go(v[i].first, v[i].second);
        memset(visited, 0, sizeof(visited));
    }

    for (int i = 0; i < n; i++) {
        if (a[i][0] == '1') ret++;
    }

    cout << ret << '\n';

    return 0;
}