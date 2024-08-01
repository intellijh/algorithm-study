#include <bits/stdc++.h>
using namespace std;

string s, ret;
int ccnt, vcnt;

bool isVowel(int idx) {
    return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while (cin >> s) {
        if (s == "end") break;
        ret = "";
        bool flag = 0;
        bool isInclude = 0;
        int prev = -1;
        ccnt = vcnt = 0;

        for (int i = 0; i < s.size(); i++) {
            int idx = s[i];
            if (isVowel(idx)) vcnt++, ccnt = 0, isInclude = 1;
            else ccnt++, vcnt = 0;
            if (vcnt == 3 || ccnt == 3) flag = 1;
            if (idx >= 1 && prev == idx && (idx != 'e' && idx != 'o')) flag = 1;
            prev = idx;
        }
        if (!isInclude) flag = 1;

        ret += "<" + s + ">";
        if (!flag) ret += " is acceptable.";
        else ret += " is not acceptable.";
        cout << ret << '\n';
    }
}