#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l, r, n, m, a[100004], mid, ret = 1e18, mx;

bool check(int mid) {
    if (mx > mid) return false;

    ll cnt = 0, temp = mid;
    for (int i = 0; i < n; i++) {
        if (mid - a[i] < 0) {
            mid = temp;
            cnt++;
        }

        mid -= a[i];
    }
    if (mid != temp) cnt++;
    return cnt <= m;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        r += a[i];
        mx = max(mx, a[i]);
    }

    l = mx;
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