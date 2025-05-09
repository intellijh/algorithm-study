#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    while (cin >> s) {
        if (s == "end") break;
        
        int m = 0, j = 0;
        char prev = '\0';
        bool flag = false;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                flag = true;
                m++;
                j = 0;
            } else {
                j++;
                m = 0;
            }

            if (s.size() == 1) break;

            if (m == 3 || j == 3) {
                flag = false;
                break;
            }

            if (prev == '\0') {
                prev = s[i];
            } else {
                if (prev == s[i] && !(s[i] == 'e' || s[i] == 'o')) {
                    flag = false;
                    break;
                }
                prev = s[i];
            }
        }

        if (flag) {
            cout << "<" << s << "> is acceptable.\n";
        } else {
            cout << "<" << s << "> is not acceptable.\n";
        }
    }

    return 0;
}