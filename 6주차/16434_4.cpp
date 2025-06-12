#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, atk, t, a, h, H, damage, ret;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> atk;
    for (int i = 0; i < n; i++) {
        cin >> t >> a >> h;
        
        if (t == 1) {
            damage = (ceil((double) h / atk) - 1) * a;
            if (H < damage) {
                ret += damage - H;
                H = 0;
            } else {
                H -= damage;
            }
        } else {
            H = min(H + h, ret);
            atk += a;
        }
    }

    cout << ret + 1 << '\n';

    return 0;
}