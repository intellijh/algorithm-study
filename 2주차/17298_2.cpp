#include <bits/stdc++.h>
using namespace std;

int n, temp, a[1000004], ret[1000004];
stack<pair<int, int>> stk;
vector<pair<int, int>> v;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        a[i] = temp;
    }

    for (int i = 0; i < n; i++) {
        if (stk.size() == 0) {
            stk.push({a[i], i});
        } else {
            while (stk.size()) {
                if (stk.top().first < a[i]) {
                    v.push_back({a[i], stk.top().second});
                    stk.pop();
                } else {
                    break;
                }
            }
            stk.push({a[i], i});
        }
    }

    while (stk.size()) {
        v.push_back({-1, stk.top().second});
        stk.pop();
    }

    sort(v.begin(), v.end(), cmp);
    for (auto it : v) cout << it.first << " ";

    return 0;
}
