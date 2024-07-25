#include <bits/stdc++.h>
using namespace std;

string input, ret, rev, odd;
int cnt;
map<char, int> mp;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> input;
    sort(input.begin(), input.end());
    for (int i = 0; i < input.size(); i++) {
        mp[input[i]]++;
    }

    for (auto it : mp) {
        if (it.second % 2 != 0) cnt++;
    }

    if (cnt > 1) {
        ret = "I'm Sorry Hansoo";
    } else {
        for (auto it : mp) {
            if (it.second % 2 != 0) {
                odd = it.first;
            }
            if (ret.size() == input.size() / 2) break;
            for (int i = 0; i < it.second / 2; i++) ret += it.first;
        }
        rev = ret;
        reverse(rev.begin(), rev.end());
        ret += odd;
        ret += rev;
    }
    cout << ret;
    
    return 0;
}