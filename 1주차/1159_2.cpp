#include <bits/stdc++.h>
using namespace std;

int N, cnt[26];
string temp, ret;

int main() {
    ios_base::sync_with_stdio; cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        cnt[temp[0] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (cnt[i] >= 5) ret += i + 'a';
    }

    if (ret.size()) cout << ret;
    else cout << "PREDAJA";
    return 0;
}