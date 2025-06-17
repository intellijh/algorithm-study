#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000001
#define prev ppp

const int INF = 1e9;
int n, ret = 1e9, dp[MAX_N], ppp[MAX_N];
vector<int> r;

int go(int num) {
    if (num == 1) return 0;
    if (num < 1) return 1e9;
    
    int& ret = dp[num];
    if (ret != INF) return ret;
    
    if (num % 3 == 0) {
        int temp = go(num / 3) + 1;
        if (ret > temp) {
            ret = temp;
            prev[num] = num / 3;
        }
    }
    if (num % 2 == 0) {
        int temp = go(num / 2) + 1;
        if (ret > temp) {
            ret = temp;
            prev[num] = num / 2;
        }
    }
    int temp = go(num - 1) + 1;
    if (ret > temp) {
        ret = temp;
        prev[num] = num - 1;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    fill(dp, dp + MAX_N, INF);
    if (n == 1) {
        cout << 0 << '\n';
        cout << 1 << '\n';
    }
    else {
        cout << go(n) << '\n';
        
        while (n >= 1) {
            cout << n << " ";
            n = prev[n];
        } 
    }

    return 0;
}