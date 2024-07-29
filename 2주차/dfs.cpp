#include <bits/stdc++.h>
using namespace std;

const int V = 10;
bool visited[V];
vector<int> adj[V];

void dfs(int start) {
    visited[start] = 1;
    cout << start << '\n';
    
    for (int i : adj[start]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[4].push_back(2);
    adj[2].push_back(5);
    dfs(1);
    return 0;
}