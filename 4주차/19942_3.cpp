#include <bits/stdc++.h>
using namespace std;

int n, ma, mb, mc, md, mn = 987654321, r;
int v[16][5];
bool flag;
vector<int> ret;

void check(vector<int> temp) {
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

void combi(int start, vector<int>& temp) {
    if (temp.size() == r) {
        check(temp);
        return;
    }

    for (int i = start + 1; i < n; i++) {
        temp.push_back(i);
        combi(i, temp);
        temp.pop_back();
    }
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
    for (r = 1; r <= n; r++) {
        combi(-1, temp);
    }

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