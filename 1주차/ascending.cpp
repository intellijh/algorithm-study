#include <bits/stdc++.h>
using namespace std;

int N, a[104];
double sum;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a, a + N);
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
        sum += a[i];
    }
    cout << "\n";
    // int temp = sum / N * 100;
    // double ret = temp / 100.0;
    cout << fixed << setprecision(2) << sum / N;
    
    return 0;
}