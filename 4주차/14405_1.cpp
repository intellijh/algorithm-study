#include <bits/stdc++.h>
using namespace std;

string s, temp, ret;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s;

    for (char c : s) {
        temp += c;
        if (temp.size() == 1) continue;
        else if (temp.size() == 2) {
            if (temp == "pi" || temp == "ka") {
                ret += temp;
                temp = "";
            }
        }
        else if (temp.size() == 3 && temp == "chu") {
            ret += temp;
            temp = "";
        }
        else break;
    }

    if (s == ret) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    
    return 0;
}