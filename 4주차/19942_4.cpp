#include <bits/stdc++.h>
using namespace std;

int n, ma, mb, mc, md, mn = 987654321, r;
int v[16][5];
bool flag;
vector<int> ret;

void check(const vector<int>& temp) {
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    for (int i : temp) {
        a += v[i][0];
        b += v[i][1];
        c += v[i][2];
        d += v[i][3];
        e += v[i][4];
    }
    
    if (mn < e || a < ma || b < mb || c < mc || d < md) return;
    if (mn > e || (mn == e && temp < ret)) {
        mn = e;
        ret = temp;
        flag = true;
    }
}

void combi(int idx, vector<int>& temp) {
    if (idx == n) {
        check(temp);
        return;
    }

    temp.push_back(idx);
    combi(idx + 1, temp);
    temp.pop_back();
    
    combi(idx + 1, temp);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    cin >> ma >> mb >> mc >> md;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> v[i][j];
        }
    }

    vector<int> temp;
    combi(0, temp);

    if (flag) {
        cout << mn << '\n';
        for (int i : ret) {
            cout << i + 1 << " ";
        }
    } else {
        cout << -1 << '\n';
    }

    return 0;
}