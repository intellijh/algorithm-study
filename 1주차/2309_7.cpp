#include <bits/stdc++.h>
using namespace std;

int a[9];
int n = 9, r = 7;

void solve() {
    if (accumulate(a, a + 7, 0) == 100) {
        for (int i = 0; i < 7; i++) cout << a[i] << '\n';
        exit(0);
    }
}

void makePermutation(int n, int r, int depth) {
    if (r == depth) {
        solve();
        return;
    }

    for (int i = depth; i < n; i++) {
        swap(a[i], a[depth]);
        makePermutation(n, r, depth + 1);
        swap(a[i], a[depth]);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int i = 0; i < 9; i++) {
        cin >> a[i];
    }
    sort(a, a + 9);

    makePermutation(n, r, 0);
    return 0;
}