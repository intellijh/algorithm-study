#include <bits/stdc++.h>
using namespace std;

int k;
char a[10], visited[10];
vector<string> ret;

bool op(char a, char b, char c) {
    if (c == '<') return a < b;
    else return a > b;
}

void go(int idx, string num) {
    if (idx == k + 1) {
        ret.push_back(num);
        return;
    }

    for (int i = 0; i <= 9; i++) {
        if (visited[i]) continue;
        if (idx == 0 || op(num[idx - 1], i + '0', a[idx - 1])) {
            visited[i] = 1;
            go(idx + 1, num + to_string(i));
            visited[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> k;
    for (int i = 0; i < k; i++) cin >> a[i];
    
    go(0, "");
    sort(ret.begin(), ret.end());
    cout << ret[ret.size() - 1] << '\n';
    cout << ret[0] << '\n';
    return 0;
}