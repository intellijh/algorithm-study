#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e16;
ll x, y, z, r = INF, l, mid, ret = INF;

bool check(ll mid) {
    if (z < (y + mid) * 100 / (x + mid)) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> x >> y;
    z = y * 100 / x;
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            ret = min(ret, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    if (ret == INF) cout << -1 << '\n';
    else cout << ret << '\n';

    return 0;
}