#include <bits/stdc++.h>
using namespace std;

int N, cntNum;
int cnt[26];
string temp;

int main() {
    ios_base::sync_with_stdio; cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        cnt[temp[0] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (cnt[i] >= 5) {
            cout << (char)(i + 'a');
            cntNum++;
        }
    }

    if (cntNum == 0) cout << "PREDAJA";
    return 0;
}