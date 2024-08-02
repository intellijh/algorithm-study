#include <bits/stdc++.h>
using namespace std;
#define prev aaaaa

const string FIN = "48:00";
int N, n, A, B, asum, bsum;
string t, prev;

void print(int sum) {
    printf("%02d:%02d\n", sum / 60, sum % 60);
}

int changeToInt(string s) {
    return atoi(s.substr(0, 2).c_str()) * 60 + atoi(s.substr(3).c_str());
}

void go(int &sum, string s) {
    sum += (changeToInt(s) - changeToInt(prev));
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> n >> t;
        if (A > B) go(asum, t);
        else if (B > A) go(bsum, t);
        n == 1 ? A++ : B++;
        prev = t;
    }
    if (A > B) go(asum, FIN);
    else if (B > A) go(bsum, FIN);

    print(asum);
    print(bsum);
    return 0;
}