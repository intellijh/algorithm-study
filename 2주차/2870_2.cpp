#include <bits/stdc++.h>
using namespace std;

int N;
string s, temp;
vector<string> ret;

bool cmp(string a, string b) {
    if (a.size() == b.size()) {
        return a < b;
    }
    return a.size() < b.size();
}

void go() {
    while (true) {
        if (temp.size() && temp.front() == '0') temp.erase(temp.begin());
        else break;
    }
    if (temp.size() == 0) temp = "0";
    ret.push_back(temp);
    temp = "";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s;
        temp = "";
        for (int j = 0; j < s.size(); j++) {
            if (s[j] < 'a') temp += s[j];
            else if (temp.size()) go();
        }
        if (temp.size()) go();
    }

    sort(ret.begin(), ret.end(), cmp);
    for (string str : ret) cout << str << '\n';
    return 0;
}