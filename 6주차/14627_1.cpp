#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, temp, l = 1, r = 1e9, mid, ret, sum;
vector<ll> v;

bool check(ll mid) {
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += v[i] / mid;
    }
    return cnt >= m;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        sum += temp;
        v.push_back(temp);
    }

    while (l <= r) {
        mid = (l + r) / (1LL *2);
        
        if (check(mid)) {
            ret = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << (sum - (ret * m)) << '\n';

    return 0;
}