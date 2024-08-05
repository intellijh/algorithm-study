#include <bits/stdc++.h>
using namespace std;

int N, a[1000004], ret[1000004], mx;
stack<int> stk;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    fill(&ret[0], &ret[0] + 1000004, -1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        while (stk.size() && a[stk.top()] < a[i]) {
            ret[stk.top()] = a[i]; stk.pop();
        }
        stk.push(i);
    }


    for (int i = 1; i <= N; i++) cout << ret[i] << " ";
    return 0;
}