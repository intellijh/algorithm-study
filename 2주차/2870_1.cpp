#include <bits/stdc++.h>
using namespace std;

int N;
string s;
vector<string> v, ret;

bool cmp(string a, string b) {
    if (a.size() == b.size()) {
        return a < b;
    }
    return a.size() < b.size();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s;

        string temp = "";
        for (int j = 0; j < s.size(); j++) {
            if (isalpha(s[j])) {
                if (temp.size()) {
                    v.push_back(temp);
                    temp = "";
                }
            } else {
                temp += s[j];
                if (isdigit(s[j]) && j == s.size() - 1) {
                    v.push_back(temp);
                }
            }
        }
    }

    for (string str : v) {
        int idx = 0;
        while (idx < str.size() && str[idx] == '0') {
            idx++;
        }
        str = str.substr(idx);
        if (str.empty()) str = "0";
        ret.push_back(str);
    }

    sort(ret.begin(), ret.end(), cmp);
    for (string str : ret) cout << str << '\n';
    return 0;
}