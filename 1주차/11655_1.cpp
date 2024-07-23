#include <bits/stdc++.h>
using namespace std;

string input,ret;
int rett[26];

int main() {
    ios_base::sync_with_stdio(false);

    getline(cin, input);

    for (int i = 0; i < input.size(); i++) {
        if (input[i] >= 97) {
            ret += input[i] + 13 <= 122 ? input[i] + 13 : input[i] + 13 - 26;
        } else if (input[i] >= 65) {
            ret += input[i] + 13 <= 90 ? input[i] + 13 : input[i] + 13 - 26;
        } else {
            ret += input[i];
        }
    }

    cout << ret << '\n';
    return 0;
}