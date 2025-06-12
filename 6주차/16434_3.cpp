#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a, ret = 1e18, l, r = 1e18, mid;

struct s {
    ll t, a, h;
} b[123456];

bool check(ll mid, ll a) {
    ll h = mid, t1, t2;
    for (int i = 0; i < n; i++) {
        if (b[i].t == 1) {
            ll cnt = b[i].h / a + (b[i].h % a ? 1 : 0);
            h -= (cnt - 1) * b[i].a;
        } else {
            a += b[i].a;
            h = min(mid, h + b[i].h);
        }
        if (h <= 0) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> a;
    for (int i = 0; i < n; i++) {
        cin >> b[i].t >> b[i].a >> b[i].h;
    }

    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid, a)) {
            ret = min(ret, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ret << '\n';

    return 0;
}