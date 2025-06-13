#include <bits/stdc++.h>
using namespace std;

int t, n, m, temp;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> t;
    while (t--) {
        cin >> n;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            mp[temp] = 1;
        }

        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> temp;
            
            if (mp[temp] == 1) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }

    return 0;
}