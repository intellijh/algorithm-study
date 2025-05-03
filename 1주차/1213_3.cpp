#include <bits/stdc++.h>
using namespace std;

string s, temp, ret, t;
int cnt;
map<char, int> mp;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s;
    sort(s.begin(), s.end());

    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++;
    }

    for (auto it : mp) {
        if (it.second % 2 != 0) cnt++;
    }
    
    if (cnt >= 2) {
        cout << "I'm Sorry Hansoo" << '\n';
        exit(0);
    }
    
    for (auto it : mp) {
        if (it.second % 2 != 0) t = it.first;
        for (int i = 0; i < it.second / 2; i++) {
            ret += it.first;
        }
    }
    temp = ret;
    reverse(temp.begin(), temp.end());
    ret += t;
    ret += temp;
    cout << ret << '\n';

    return 0;
}