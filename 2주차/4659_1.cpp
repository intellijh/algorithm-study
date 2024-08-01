#include <bits/stdc++.h>
using namespace std;

string s, ret;
char temp;
map<char, int> mp;
bool pwd;

bool solve(string s) {
    bool ret = false;
    queue<char> q;

    for (int i = 0; i < s.size(); i++) {
        if (mp[s[i]] == 1) {
            ret = true;
            break;
        }
    }
    
    for (int i = 0; i < s.size(); i++) {
        temp = s[i];
        if (q.size()) {
            if (q.back() == temp && temp != 'e' && temp != 'o' ) {
                ret = false;
                break;
            }

            if (q.size() >= 2) {
                if (mp[q.front()] == mp[q.back()] && mp[q.back()] == mp[temp]) {
                    ret = false;
                    break;
                }
                q.pop();
            }
        }
        q.push(temp);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    mp['a'] = 1; mp['e'] = 1; mp['i'] = 1; mp['o'] = 1; mp['u'] = 1;
    while (cin >> s) {
        if (s == "end") break;
        ret = "";

        pwd = solve(s);
        ret += "<" + s + ">";
        if (pwd) ret += " is acceptable.";
        else ret += " is not acceptable.";
        cout << ret << '\n';
    }
}