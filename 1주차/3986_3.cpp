#include <bits/stdc++.h>
using namespace std;

vector<string> v;
int n, ret;
string s;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        v.push_back(s);
    }
    
    for (int i = 0; i < n; i++) {
        stack<char> stk;
        
        for (int j = 0; j < v[i].size(); j++) {
            if (stk.empty()) {
                stk.push(v[i][j]);
            } else {
                if (stk.top() == v[i][j]) {
                    stk.pop();
                } else {
                    stk.push(v[i][j]);
                }
            }
        }

        if (stk.empty()) ret++;
    }

    cout << ret << '\n';

    return 0;
}