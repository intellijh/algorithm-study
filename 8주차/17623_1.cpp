#include <bits/stdc++.h>
using namespace std;

string dp[1004];
char a[] = {'(', ')', '{', '}', '[', ']'};
int t, n;
map<char, char> mp;

bool check(string before, string after) {
    if (before == "" && after == "") return false;
    if (before == "") return true;
    if (before.size() == after.size()) return after < before;
    return before.size() > after.size();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int i = 0; i < 6; i++) {
        mp[i + '1'] = a[i];
    }

    dp[1] = "12";
    dp[2] = "34";
    dp[3] = "56";

    for (int idx = 1; idx <= 1000; idx++) {
        if (idx % 2 == 0 && check(dp[idx], "1" + dp[idx / 2] + "2")) dp[idx] = "1" + dp[idx / 2] + "2";
        if (idx % 3 == 0 && check(dp[idx], "3" + dp[idx / 3] + "4")) dp[idx] = "3" + dp[idx / 3] + "4";
        if (idx % 5 == 0 && check(dp[idx], "5" + dp[idx / 5] + "6")) dp[idx] = "5" + dp[idx / 5] + "6";

        for (int i = 1; i <= idx; i++) {
            if (check(dp[idx], dp[i] + dp[idx - i])) dp[idx] = dp[i] + dp[idx - i];
        }
    }

    cin >> t;
    while (t--) {
        cin >> n;

        for (char a : dp[n]) cout << mp[a];
        cout << '\n';
    }

    return 0;
}