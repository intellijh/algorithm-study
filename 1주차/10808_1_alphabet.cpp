#include <bits/stdc++.h>
using namespace std;

string input;
int a[26];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> input;
    for (int i = 0; i < input.size(); i++) {
       a[input[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        cout << a[i] << ' ';
    }
    
    return 0;
}