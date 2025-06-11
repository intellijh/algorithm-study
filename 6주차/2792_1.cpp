#include <bits/stdc++.h>
using namespace std;

int n, m, a[300000], l = 1, r, mid, ret = 1987654321;

bool check(int target) {
    int ret = 0;
    for (int i = 0; i < m; i++) {
        ret += a[i] / target;
        if (a[i] % target) ret++;
    }

    return ret <= n;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        r = max(r, a[i]);
    }

    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            ret = min(ret, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ret << '\n';

    return 0;
}