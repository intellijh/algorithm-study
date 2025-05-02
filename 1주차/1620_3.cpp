#include <bits/stdc++.h>
using namespace std;

int n, m;
string s, temp;
map<int, string> mp;
map<string, int> mp2;

int main() {
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        mp[i] = s;
        mp2[s] = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> temp;
        int a = atoi(temp.c_str());
        if (a == 0) {
            cout << mp2[temp] << '\n';
        } else {
            cout << mp[a] << '\n';
        }
    }

    return 0;
}