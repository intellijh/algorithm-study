#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int T, N, ret;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N;
        ret = 0;
        for (int i = 5; i <= N; i *= 5) {
            ret += N / i;
        }
        cout << ret << '\n';
    }
    return 0;
}