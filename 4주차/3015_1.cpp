#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, temp, ret;
stack<pair<ll, ll>> stk;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        int cnt = 1;
        while (stk.size() && stk.top().first <= temp) {
            ret += stk.top().second;
            if (stk.top().first == temp) {
                cnt = stk.top().second + 1;
            } else {
                cnt = 1;
            }
            stk.pop();
        }
        if (stk.size()) ret++;
        stk.push({temp, cnt});
    }

    cout << ret << '\n';
    return 0;
}