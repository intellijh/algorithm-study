#include <bits/stdc++.h>
using namespace std;

int n, num, lis[1004], len;
pair<int, int> p[1004];
stack<int> stk;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        auto lower_pos = lower_bound(lis, lis + len, num);
        int _pos = (int) (lower_pos - lis);
        if (*lower_pos == 0) len++;
        *lower_pos = num;
        p[i].first = _pos;
        p[i].second = num;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (len - 1 == p[i].first) {
            stk.push(p[i].second);
            len--;
        }
    }

    cout << stk.size() << '\n';
    while(stk.size()) {
        cout << stk.top() << " "; stk.pop();
    }

    return 0;
}