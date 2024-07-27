#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ret, cnt;

int main() {
    while (scanf("%lld", &n) != EOF) {
        ret = 1;
        cnt = 1;
        while (ret % n) {
            ret = (ret * 10 + 1) % n;
            cnt++;
        }
        cout << cnt << '\n';
    }
    
    return 0;
}