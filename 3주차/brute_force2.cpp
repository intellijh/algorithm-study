#include <bits/stdc++.h>
using namespace std;

int N, a[104], ret;

bool isPrime(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int go(int idx, int sum) {
    if (idx == N) {
        return isPrime(sum);
    }
    return go(idx + 1, sum + a[idx]) + go(idx + 1, sum);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << go(0, 0) << '\n';
    return 0;
}