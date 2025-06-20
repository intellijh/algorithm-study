#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int a[14][14], ret = INF;
map<int, int> mp;

bool check(int y, int x, int cnt) {
    for (int i = y; i < y + cnt; i++) {
        for (int j = x; j < x + cnt; j++) {
            if (a[i][j] == 0) return false;
        }
    }
    return true;
}

void draw(int y, int x, int cnt, int value) {
    for (int i = y; i < y + cnt; i++) {
        for (int j = x; j < x + cnt; j++) {
            a[i][j] = value;
        }
    }
}

void dfs(int y, int x, int cnt) {
    if (cnt >= ret) return;

    if (x == 10) {
        dfs(y + 1, 0, cnt);
        return;
    }

    if (y == 10) {
        ret = min(ret, cnt);
        return;
    }

    if (a[y][x] == 0) {
        dfs(y, x + 1, cnt);
        return;
    }

    for (int i = 5; i >= 1; i--) {
        if (mp[i] == 5) continue;
        if (check(y, x, i)) {
            mp[i]++;
            draw(y, x, i, 0);
            dfs(y, x + 1, cnt + 1);
            draw(y, x, i, 1);
            mp[i]--;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> a[i][j];
        }
    }

    dfs(0, 0, 0);
    if (ret == INF) cout << -1 << '\n';
    else cout << ret << '\n';

    return 0;
}