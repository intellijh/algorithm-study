#include <bits/stdc++.h>
using namespace std;

int a[9];
int n = 9, r = 7;

void solve() {
    int sum = accumulate(a, a + r, 0);
    if (sum == 100) {
        for (int i = 0; i < r; i++) {
            cout << a[i] << '\n';
        }
        exit(0);
    }
}

void print() {
    for (int i = 0; i < r; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort (a, a + n);

    makePermutation(n, r, 0);
    return 0;
}