#include <bits/stdc++.h>
using namespace std;

int N, mp, mf, ms, mv, ret = 987654321;
int p, f, s, v, c;
struct A {
    int mp, mf, ms, mv, cost;
} a[16];
map<int, vector<vector<int>>> retV;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < N; i++) {
        cin >> a[i].mp >> a[i].mf >> a[i].ms >> a[i].mv >> a[i].cost;
    }

    for (int i = 1; i < (1 << N); i++) {
        p = f = s = v = c = 0;
        vector<int> vv;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                p += a[j].mp;
                f += a[j].mf;
                s += a[j].ms;
                v += a[j].mv;
                c += a[j].cost;
                vv.push_back(j + 1);
            }
        }

        if (p >= mp && f >= mf && s >= ms && v >= mv) {
            if (ret >= c) {
                ret = c;
                retV[ret].push_back(vv);
            }
        }
    }

    if (ret == 987654321) {
        cout << -1;
    } else {
        cout << ret << '\n';
        sort(retV[ret].begin(), retV[ret].end());
        for (int i : retV[ret][0]) {
            cout << i << " ";
        }
    }
    return 0;
}