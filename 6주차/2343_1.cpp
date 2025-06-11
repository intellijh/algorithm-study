#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l, r, n, m, a[100004], mid, psum[100004], ret = 1e18;

bool check(int s) {
    int cnt = 0, idx = 0;
    ll temp = 0;
    for (int i = 1; i <= n; i++) {
        temp = psum[i] - psum[idx];
        if (temp > s) {
            idx = i - 1;
            cnt++;
        }
    }
    if (psum[n] - psum[idx] <= s) cnt++;
    return cnt <= m;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        r += a[i];
        psum[i] = psum[i - 1] + a[i];
        l = max(l, a[i]);
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