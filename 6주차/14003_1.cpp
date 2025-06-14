#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e9 + 4;
ll n, lis[1000001], ret, num, len;
pair<ll, ll> ans[1000001];
stack<ll> stk;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    fill(lis, lis + 1000001, INF);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        auto lower_pos = lower_bound(lis, lis + len, num);
        int pos = (int) (lower_pos - lis);
        if (*lower_pos == INF) len++;
        *lower_pos = num;
        ans[i].first = pos;
        ans[i].second = num;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (ans[i].first == len - 1) {
            stk.push(ans[i].second); len--;
        }
    }

    cout << stk.size() << '\n';
    while (stk.size()) {
        cout << stk.top() << " "; stk.pop();
    }

    return 0;
}