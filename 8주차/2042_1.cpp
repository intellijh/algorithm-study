#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> tree;
ll n, m, k, temp, a, b, c;

ll _sum(int idx) {
    ll ret = 0;
    while (idx > 0) {
        ret += tree[idx];
        idx -= idx & -idx;
    }
    return ret;
}

void update(int idx, ll value) {
    while (idx <= n) {
        tree[idx] += value;
        idx += idx & -idx;
    }
}

ll sum(int s, int e) {
    return _sum(e) - _sum(s - 1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    tree.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        update(i, temp);
    }
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;

        if (a == 1) {
            ll temp = sum(b, b);
            temp = c - temp;
            update(b, temp);
        } else {
            cout << sum(b, c) << '\n';
        }
    }

    return 0;
}