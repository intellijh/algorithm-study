#include <bits/stdc++.h>
using namespace std;

int main() {
    string dopa = "umzunsik";
    string dopa2 = dopa.substr(0, 3);
    cout << dopa2 << "\n";

    reverse(dopa2.begin(), dopa2.end());
    cout << dopa2 << "\n";

    dopa2 += "umzunsik";
    cout << dopa2 << "\n";
    return 0;
}