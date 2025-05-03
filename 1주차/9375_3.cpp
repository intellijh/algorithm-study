#include <bits/stdc++.h>
using namespace std;

int t, n;
long long ret;
map<string, int> mp;
string s1, s2;


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;

        if (n == 0) {
            cout << 0 << '\n';
            continue;
        }
        
        ret = 1;
        mp.clear();
        for (int i = 0; i < n; i++) {
            cin >> s1 >> s2;
            mp[s2]++;
        }

        for (auto it : mp) {
            ret *= (it.second + 1);
        }

        cout << ret - 1 << '\n';
    }

    return 0;
}