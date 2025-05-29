#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, k, ret, a[104], visited[104];
vector<int> v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < k; i++) {
        if (!visited[a[i]]) {
            if (v.size() == n) {
                int mx = -1, pos = -1;
                for (int b : v) {
                    int temp = INF;
                    for (int j = i + 1; j < k; j++) {
                        if (a[j] == b) {
                            temp = j;
                            break;
                        }
                    }
                    if (mx < temp) {
                        mx = temp;
                        pos = b;
                    }
                }
                visited[pos] = 0; ret++;
                v.erase(find(v.begin(), v.end(), pos));
            }
            visited[a[i]] = 1;
            v.push_back(a[i]);
        }
    }

    cout << ret << '\n';

    return 0;
}