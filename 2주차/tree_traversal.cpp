#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10];
bool visited[10];

void postOrder(int here) {
    if (!visited[here]) {
        if (adj[here].size() == 1) postOrder(adj[here][0]);
        if (adj[here].size() == 2) {
            postOrder(adj[here][0]);
            postOrder(adj[here][1]);
        }
        visited[here] = 1;
        cout << here << " ";
    }
}

void preOrder(int here) {
    if (!visited[here]) {
        visited[here] = 1;
        cout << here << " ";
        if (adj[here].size() == 1) preOrder(adj[here][0]);
        if (adj[here].size() == 2) {
            preOrder(adj[here][0]);
            preOrder(adj[here][1]);
        }
    }
}

void inOrder(int here) {
    if (!visited[here]) {
        if (adj[here].size() == 1) {
            inOrder(adj[here][0]);
            visited[here] = 1;
            cout << here << " ";
        } else if (adj[here].size() == 2) {
            inOrder(adj[here][0]);
            visited[here] = 1;
            cout << here << " ";
            inOrder(adj[here][1]);
        } else {
            visited[here] = 1;
            cout << here << " ";
        }
    }
}

int main() {
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);

    int root = 1;
    cout << "트리순회\n";
    cout << "postOrder\n";
    postOrder(root); memset(visited, 0, sizeof(visited));
    cout << '\n';
    cout << "preOrder\n";
    preOrder(root); memset(visited, 0, sizeof(visited));
    cout << '\n';
    cout << "inOrder\n";
    inOrder(root); memset(visited, 0, sizeof(visited));
    cout << '\n';
    return 0;
}