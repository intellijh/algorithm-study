#include <bits/stdc++.h>
using namespace std;

int n;
string s;
stack<int> stk;
int ret;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;

    stk.push(-1);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') stk.push(i);
        else {
            stk.pop();
            if (!stk.empty()) {
                ret = max(ret, i - stk.top());
            } else {
                stk.push(i);
            }
        }
    }

    cout << ret << '\n';
}
