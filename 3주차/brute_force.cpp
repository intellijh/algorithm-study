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

void combi(int start, vector<int> &b, int k) {
    if (b.size() == k) {
        int sum = 0;
        sum = accumulate(b.begin(), b.end(), 0);
        if (isPrime(sum)) ret++;
        return;
    }

    for (int i = start + 1; i < N; i++) {
        b.push_back(a[i]);
        combi(i, b, k);
        b.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= N; i++) {
        vector<int> b;
        combi(-1, b, i);
    }
    cout << ret;
    return 0;
}