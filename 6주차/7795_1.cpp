#include <bits/stdc++.h>
using namespace std;

int t, n, m, temp;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n >> m;
        vector<int> a, b;
        int ret = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> temp;
            a.push_back(temp);
        }
        for (int i = 0; i < m; i++) {
            cin >> temp;
            b.push_back(temp);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        for (int i = 0; i < n; i++) {
            auto it = lower_bound(b.begin(), b.end(), a[i]);
            ret += it - b.begin();
        }
        cout << ret << '\n';
    }

    return 0;
}