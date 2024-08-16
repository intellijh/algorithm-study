#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> mp;
    mp["haha"] = 1;
    
    auto it = mp.find("haha");
    //map<string, int>::iterator 반환
    cout << (*it).first << '\n';
    cout << it -> first << '\n';

    for (auto it : mp) { 
        //pair<const string, int> 반환
        cout << it.first;
    }
    return 0;
}