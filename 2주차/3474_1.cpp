#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int T, N, two, five;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N;
        five = two = 0;

        for (int i = 2; i <= N; i *= 2) {
            two += N / i;
        }

        for (int i = 5; i <= N; i *= 5) {
            five += N / i;
        }
        cout << min(two, five) << '\n';
    }
    return 0;
}