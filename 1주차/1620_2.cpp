#include <bits/stdc++.h>
using namespace std;

int N, M;
string q, temp;
map<string, int> a;
map<int, string> n;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        a[temp] = i;
        n[i] = temp;
    }
    for (int i = 0; i < M; i++) {
        cin >> q;

        int qToInt = atoi(q.c_str());
        if (qToInt) cout << n[qToInt] << '\n';
        else cout << a[q] << '\n';
    }
    return 0;
}