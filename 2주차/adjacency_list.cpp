#include <bits/stdc++.h>
using namespace std;

bool visited[10];
vector<int> adj[10];

void go(int from) {
    cout << from << '\n';
    visited[from] = 1;

    for (int i : adj[from]) {
        if (visited[i]) continue;
        go(i);
    }
}

int main() {
    adj[1].push_back(2);
    adj[1].push_back(3);

    adj[2].push_back(1);

    adj[3].push_back(1);
    adj[3].push_back(4);

    adj[4].push_back(3);

    for (int i = 0; i < 10; i++) {
        if (visited[i] == 0 && adj[i].size()) {
            go(i);
        }
    }
    return 0;
}