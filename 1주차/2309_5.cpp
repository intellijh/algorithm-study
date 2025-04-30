#include <bits/stdc++.h>
using namespace std;

const int n = 9;
int temp, sum;
vector<int> a;

void solve(int i, int j) {
    int tsum = sum - a[i] - a[j];
    if (tsum == 100) {
        for (int k = 0; k < n; k++) {
            if (k == i || k == j) continue;
            cout << a[k] << '\n';
        }
        exit(0);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    for (int i = 0; i < n; i++) {
        cin >> temp;
        a.push_back(temp);
        sum += temp;
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            solve(i, j);
        }
    }
    return 0;
}