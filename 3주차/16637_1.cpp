#include <bits/stdc++.h>
using namespace std;

int N, ret = -987654321;
vector<int> n;
vector<char> o;
string s;

int op(char a, int b, int c) {
    if (a == '+') return b + c;
    if (a == '-') return b - c;
    if (a == '*') return b * c;
}

void go(int idx, int sum) {
    if (idx == n.size() - 1) {
        ret = max(ret, sum);
        return;
    }
    
    go(idx + 1, op(o[idx], sum, n[idx + 1]));
    if (idx + 2 < n.size()) {
        int temp = op(o[idx + 1], n[idx + 1], n[idx + 2]);
        go(idx + 2, op(o[idx], sum, temp));
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> s;
    for (char a : s) {
        if ('0' <= a && a <= '9') n.push_back(a - '0');
        else o.push_back(a);
    }

    go(0, n[0]);
    cout << ret;
    return 0;
}