#include <bits/stdc++.h>
using namespace std;

string s;
int n;
vector<string> ret;

bool cmp(string s1, string s2) {
    if (s1.size() == s2.size()) {
        return s1 < s2;
    }
    return s1.size() < s2.size();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;

        string temp = "";
        for (int j = 0; j < s.size(); j++) {
            if ('0' <= s[j] && s[j] <= '9') {
                if (temp.size() == 1 && temp == "0") {
                    temp = "";
                }
                temp += s[j];
            } else {
                if (temp.size()) {
                    ret.push_back(temp);
                    temp = "";
                }
            }
            
            if (j == s.size() -1 && temp.size()) {
                ret.push_back(temp);
            }
        }
    }

    sort(ret.begin(), ret.end(), cmp);

    for (string i : ret) {
        cout << i << '\n';
    }

    return 0;
}