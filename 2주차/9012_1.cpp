#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> T;
    while (T--) {
        stack<char> stk;
        cin >> s;
        for (char a : s) {
            if (stk.size()) {
                if (stk.top() == '(' && a == ')') stk.pop();
                else stk.push(a);
            } else stk.push(a);
        }

        if (stk.size()) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
    return 0;
}