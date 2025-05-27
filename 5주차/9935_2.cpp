#include <bits/stdc++.h>
using namespace std;

string s1, s2, ret;
stack<char> stk;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s1 >> s2;
    
    for (char c : s1) {
        stk.push(c);
        if (stk.size() >= s2.size() && stk.top() == s2[s2.size() - 1]) {
            for (char i : s2) {
                ret += stk.top();
                stk.pop();
            }
            reverse(ret.begin(), ret.end());

            if (ret != s2) {
                for (char i : ret) {
                    stk.push(i);
                }
            }
            ret = "";
        }
    }

    if (stk.size()) {
        while (stk.size()) {
            ret += stk.top(); stk.pop();
        } 
        reverse(ret.begin(), ret.end());
        cout << ret << '\n';
    } else cout << "FRULA" << '\n';

    return 0;
}