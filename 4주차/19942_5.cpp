#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, mp, mf, ms, mv, ret = INF, b, c, d, e, sum;

struct A {
    int b, c, d, e, sum;
} a[16];

map<int, vector<vector<int>>> ret_v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < n; i++) {
        cin >> a[i].b >> a[i].c >> a[i].d >> a[i].e >> a[i].sum;
    }

    for (int i = 1; i < (1 << n); i++) {
        b = c = d = e = sum = 0;
        vector<int> v;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                v.push_back(j + 1);
                b += a[j].b;
                c += a[j].c;
                d += a[j].d;
                e += a[j].e;
                sum += a[j].sum;
            }
        }

        if (b >= mp && c >= mf && d >= ms && e >= mv && ret >= sum) {
            ret = sum;
            ret_v[ret].push_back(v);
        }
    }


    if (ret == INF) cout << -1 << '\n';
    else {
        cout << ret << '\n';
        sort(ret_v[ret].begin(), ret_v[ret].end());
        for (int i : ret_v[ret][0]) {
            cout << i << " ";
        }
    }
    return 0;
}