#include <bits/stdc++.h>
using namespace std;

string input, ret;
char mid;
int cnt[200], flag;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> input;
    for (char a : input) cnt[a]++;

    for (int i = 'Z'; i >= 'A'; i--) {
        if (cnt[i]) {
            if (cnt[i] & 1) {
                mid = i;
                flag++;
                cnt[i]--;
            }
            if (flag == 2) break;

            for (int j = 0; j < cnt[i]; j += 2) {
                ret = char(i) + ret;
                ret += char(i);
            }
        }
    }

    if (mid) ret.insert(ret.begin() + ret.size() / 2, mid);
    if (flag == 2) {
        ret = "I'm Sorry Hansoo";
    }
    cout << ret;
    
    return 0;
}