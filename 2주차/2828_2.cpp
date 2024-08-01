#include <bits/stdc++.h>
using namespace std;

int N, M, J, temp, ret, l, r;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> J;

    l = 1;
    for (int i = 0; i < J; i++) {
        cin >> temp;
        r = l + M - 1;

        if (l <= temp && temp <= r) continue;
        else {
            if (temp < l) {
                ret += l - temp;
                l = temp;
            } else {
                ret += temp - r;
                l += temp -r;
            }
        }
    }

    cout << ret;
    return 0;
}