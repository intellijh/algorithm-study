#include <bits/stdc++.h>
using namespace std;

string INF;
string mx, dp[104];
int t, n, a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

string str_min(string s1, string s2) {
    if (s1.size() == s2.size()) {
        return min(s1, s2);
    } else {
        return s1.size() > s2.size() ? s2 : s1;
    }
}

string go(int size) {
    if (size == 0) return "";

    string& ret = dp[size];
    if (ret != INF) return ret;

    for (int i = 0; i <= 9; i++) {
        if (size - a[i] >= 0) {            
            if (i == 0 && size == n) continue;
            ret = str_min(ret, to_string(i) + go(size - a[i]));
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int i = 0; i <= 50; i++) INF += "9";
    
    cin >> t;
    while (t--) {
        cin >> n;
        mx = "";
        
        fill(dp, dp + 104, INF);
        if (n % 2 == 0) {
            for (int i = 0; i < n / 2; i++) mx += "1";
        } else {
            mx = "7";
            for (int i = 0; i < (n - 3) / 2; i++) mx += "1";
        }

        cout << go(n) << " ";
        cout << mx << '\n';
    }

    return 0;
}