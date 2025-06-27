#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n, x, y;
vector<pair<int, int>> a;
vector<int> _y, tree;

int find_index(vector<int>& v, int value) {
    int lo = 0, hi = v.size() - 1;
    int mid = 0;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (v[mid] == value) {
            return mid;
        } else if (v[mid] > value) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
}

void update(int idx, int value) {
    while (idx <= n) {
        tree[idx] += value;
        idx += idx & -idx;
    }
}

int sum(int idx) {
    int ret = 0;
    while (idx > 0) {
        ret += tree[idx];
        idx -= idx & -idx;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        a.clear(); _y.clear(); tree.clear();
        tree.resize(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            a.push_back({x, y * -1});
            _y.push_back(y * -1);
        }
        sort(a.begin(), a.end());
        sort(_y.begin(), _y.end());

        update(find_index(_y, a[0].second) + 1, 1);
        ll ret = 0;
        for (int i = 1; i < n; i++) {
            int idx = find_index(_y, a[i].second) + 1;
            ret += sum(idx); update(idx, 1);
        }
        cout << ret << '\n';
    }

    return 0;
}