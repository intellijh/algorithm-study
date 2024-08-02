#include <bits/stdc++.h>
using namespace std;

int N, cnt;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;

    for (int i = 666; i < 10000666; i++) {
        if (to_string(i).find("666") == string::npos) continue;
        if (++cnt == N) {
            cout << i;
            break;
        }
    }
    return 0;
}