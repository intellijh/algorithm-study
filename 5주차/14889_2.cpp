#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, a[24][24], ret = INF;

void go(vector<int>& x, vector<int>& y) {
    pair<int, int> temp;
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            temp.first += a[x[i]][x[j]];
            temp.second += a[y[i]][y[j]];
        }
    }
    ret = min(ret, abs(temp.first - temp.second));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < (1 << n); i++) {
        if (__builtin_popcount(i) != n / 2) continue;
        vector<int> start, link;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) start.push_back(j);
            else link.push_back(j);
        }
        go(start, link);
    }

    cout << ret << '\n';
    return 0;
}