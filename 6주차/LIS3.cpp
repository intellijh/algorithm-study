#include <bits/stdc++.h>
using namespace std;
#define prev ppp

int n, lis[1001], len, num;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        auto lowerPos = lower_bound(lis, lis + len, num);
        if (*lowerPos == 0) len++;
        *lowerPos = num;
    }

    cout << len << '\n';

    return 0;
}
