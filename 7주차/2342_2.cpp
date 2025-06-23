#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int input, n, dp[100004][5][5], a = 4, b = 4;
vector<int> v;

int check(int foot, int pos) {
    if (foot == pos) return 1;

    if (foot == 4) return 2;

    if ((foot + 2) % 4 == pos) return 4;

    return 3;
}

int go(int idx, int a, int b) {
    if (idx == n) return 0;

    int& ret = dp[idx][a][b];
    if (ret != 1e9) return ret;

    if (v[idx] == a || v[idx] == b) {
        return ret = min(ret, go(idx + 1, a, b) + 1);
    }
    
    int pos1= (v[idx] + 1) % 4;
    int pos2= (v[idx] + 3) % 4;

    ret = min(ret, go(idx + 1, v[idx], b) + check(a, v[idx]));
    ret = min(ret, go(idx + 1, a, v[idx]) + check(b, v[idx]));

    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while (cin >> input) {
        if (input == 0) break;
        v.push_back(--input);
    }

    fill(&dp[0][0][0], &dp[0][0][0] + 100004 * 5 * 5, INF);
    n = v.size();
    cout << go(0, a, b) << '\n';

    return 0;
}