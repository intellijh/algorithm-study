#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define max_n 200004

const ll mod = 1e9 + 7;
ll ret = 1;
int n;
vector<ll> tree_cnt(max_n, 0), tree_sum(max_n, 0);

ll _sum(vector<ll>& tree, int idx) {
    ll ret = 0;
    while (idx > 0) {
        ret += tree[idx];
        idx -= idx & -idx;
    }
    return ret;
}

ll sum(vector<ll>& tree, int s, int e) {
    return _sum(tree, e) - _sum(tree, s - 1);
}

void update(vector<ll>& tree, int idx, int value) {
    while (idx <= max_n) {
        tree[idx] += value;
        idx += idx & -idx;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value; value++;

        if (i != 0) {
            ll left = value * sum(tree_cnt, 1, value - 1) - sum(tree_sum, 1, value - 1);
            ll right = sum(tree_sum, value + 1, max_n) - sum(tree_cnt, value + 1, max_n) * value;

            ret *= (left + right) % mod;
            ret %= mod;
        }

        update(tree_cnt, value, 1);
        update(tree_sum, value, value);
    }

    cout << ret << '\n';

    return 0;
}