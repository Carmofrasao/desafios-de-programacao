#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// g++ -static -std=c++11 -O2 -Wall -g first.cpp

int main() {
    cin.tie(0); ios::sync_with_stdio(0);

    // code 

    auto n = 0;
    while (cin >> n){
        vector<ll>a;
        auto mochila = 0;
        for(auto i = 0; i < n; i++){
            auto aux = 0;
            cin >> aux;
            a.push_back(aux);
        }
        for(auto i = 0; i < n; i++){
            if(a[i] <= 10){
                continue;
            }
            else{
                mochila += a[i] - 10;
            }
        }
        cout << mochila << '\n';
    }
}