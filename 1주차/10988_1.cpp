#include <bits/stdc++.h>
using namespace std;

string input;
int endNum;

int main() {
    cin >> input;

    for (int i = 0; i < input.size(); i++) {
        endNum = input.size() - 1 - i;
        if (input[i] != input[endNum]) break;
        if (i >= endNum) {
            cout << 1;
            exit(0);
        }
    }
    cout << 0;
    return 0;
}