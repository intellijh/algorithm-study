#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ret;
int T, n;
string temp, str;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    //테스트 케이스
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n;
        map<string, int> cnt;
        for (int i = 0; i < n; i++) {
            cin >> temp >> str;
            cnt[str]++;
        }

        ret = 1;
        for (auto it : cnt) {
            ret *= it.second + 1;
        }
        ret--;
        cout << ret << '\n';
    }
    return 0;
}