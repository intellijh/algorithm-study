#include <bits/stdc++.h>
using namespace std;

int T, n, ret;
string str;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    //테스트 케이스
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n;
        string bufferflush;
        getline(cin, bufferflush);
        map<string, int> cnt;
        for (int i = 0; i < n; i++) {
            getline(cin, str);
            str = str.substr(str.find(" ") + 1);
            cnt[str]++;
        }

        ret = 1;
        for (auto it : cnt) {
            ret *= it.second + 1;
        }
        ret -= 1;
        cout << ret << '\n';
    }
    return 0;
}