#include <bits/stdc++.h>
using namespace std;

const int FIN = 48 * 60;
pair<int, int> chk;
int N, n, ret, score;
string t;
map<int, int> mp;

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> n >> t;
        ret = 0;

        int m = atoi(t.substr(0, 2).c_str()) * 60;
        int s = atoi(t.substr(3).c_str());
        int time = m + s;
        if (score == 0) tie(chk.first, chk.second) = {n, time};
        if (n == 1) score++;
        else score--;

        if (score == 0) mp[chk.first] += time - chk.second;
    }
    if (score != 0) {
        mp[chk.first] += FIN - chk.second;
    }

    for (int i = 1; i <= 2; i++) {
        printf("%02d:%02d\n",mp[i]/60 ,mp[i]%60);
    }

    return 0;
}