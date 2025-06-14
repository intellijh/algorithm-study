#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, temp, l, r = 60000000004, mid, ret;
vector<ll> v;

bool check(ll mid) {
    ll temp = m;
    for (int i = 0; i < m; i++) {
        temp += mid / v[i];
    }
    return temp >= n;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    if (n <= m) cout << n << '\n';
    else {
        while (l <= r) {
            mid = (l + r) / 2;
            if (check(mid)) {
                ret = mid;
                r = mid - 1;
            } else l = mid + 1;
        }

        temp = m;
        for (int i = 0; i < m; i++) {
            temp += (ret - 1) / v[i];
        }

        for (int i = 0; i < m; i++) {
            if (ret % v[i] == 0) temp++;
            if (temp == n) {
                cout << i + 1 << '\n';
                return 0;
            }
        }
    }


    return 0;
}