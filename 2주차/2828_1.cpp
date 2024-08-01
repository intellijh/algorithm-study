#include <bits/stdc++.h>
using namespace std;

int N, M, J, a[21], ret, here = 1, cnt;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> J;
    for (int i = 0; i < J; i++) cin >> a[i];

    while (cnt < J) {
        if (here + M - 1 >= a[cnt] && here <= a[cnt]) {
            cnt++;
            continue;
        } else if (a[cnt] > here) {
            ret++;
            here++;
        } else if (a[cnt] < here) {
            ret++;
            here--;
        }
    }

    cout << ret;
    return 0;
}