#include <bits/stdc++.h>
using namespace std;

int N, ret;
string s[104];

void solve(string a) {
    stack<char> stk;
    stk.push(a[0]);
    for (int i = 1; i < a.size(); i++) {
        if (!stk.empty() && stk.top() == a[i]) {
            stk.pop();
        } else {
            stk.push(a[i]);
        }
    }

    if (stk.empty()) {
        ret++;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < N; i++) {
        solve(s[i]);
    }    

    cout << ret << '\n';
    return 0;
}