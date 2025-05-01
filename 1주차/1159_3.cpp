#include <bits/stdc++.h>
using namespace std;

int n, cnt;
string s;
map<char, int> mp;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        mp[s[0]]++;
    }


    for (auto it : mp) {
        if (it.second >= 5) {
            cnt++;
            cout << it.first;
        }
    }


    if (cnt == 0) {
        cout << "PREDAJA" << '\n';
    }
    return 0;
}