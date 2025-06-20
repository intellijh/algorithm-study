#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, ret = 1e9;
map<pair<int, int>, int> mp;

struct S {
    int x, y, cnt;
};

void go(int x, int y, int cnt) {
    queue<S> q;
    q.push({x, y, cnt});

    while (q.size()) {
        S s = q.front(); q.pop();
        x = s.x; y = s.y; cnt = s.cnt;
        if (x == c && y == d) {
            ret = cnt;
            return;
        }

        if (mp[{x, y}] > 0) continue;
        mp[{x, y}] = cnt;

        q.push({a, y, cnt + 1});
        q.push({x, b, cnt + 1});
        q.push({0, y, cnt + 1});
        q.push({x, 0, cnt + 1});
        int t1 = min(a, x + y);
        int t2 = min(b, x + y);
        q.push({t1, y - (t1 - x), cnt + 1});
        q.push({x - (t2 - y), t2, cnt + 1});
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> a >> b >> c >> d;

    go(0, 0, 0);

    if (ret == 1e9) cout << -1 << '\n';
    else cout << ret << '\n';

    return 0;
}