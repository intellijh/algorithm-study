#include <bits/stdc++.h>
using namespace std;

int N, ret;
string s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s;
        stack<char> stk;

        for (char a : s) {
            if (!stk.empty() && stk.top() == a) stk.pop();
            else stk.push(a);
        }
        if (stk.empty()) ret++;
    }

    cout << ret << '\n';
    return 0;
}