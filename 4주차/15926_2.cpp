#include <bits/stdc++.h>
using namespace std;

int n, ret, d[200004], cnt;
string s;
stack<int> stk;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') stk.push(i);
        else if (stk.size()) {
            d[i] = d[stk.top()] = 1;
            stk.pop();
        }
    }

    for (int i = 0; i < n; i++) {
        if (d[i] == 1) cnt++;
        else cnt = 0;

        ret = max(ret, cnt);
    }
    cout << ret << '\n';
}
