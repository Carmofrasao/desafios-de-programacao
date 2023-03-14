#include <bits/stdc++.h>

using namespace std;
using ll = long unsigned int;

// g++ -static -std=c++11 -O2 -Wall -g first.cpp

int main() {
    cin.tie(0); ios::sync_with_stdio(0);

    // code 

    vector<ll>c;
    vector<ll>v;
    ll n, i, m, p;
    while (cin >> n){
        cin >> i >> m >> p;
        ll aux = 0;
        for(ll i = 0; i < m; i++){
            cin >> aux;
            c.push_back(aux);
        }
        for (ll i = 0; i < m; i++){
            cin >> aux;
            v.push_back(aux);
        }

        ll total = 0;
        vector<ll>anos;

        for (ll k = 0; k < n; k++){
            if((c[i-1] + c[i] > p) || (i >= m)){
                total += p;
                i = 1;
                anos.push_back(k+1);
            }
            else{
                total += c[i-1];
                i++;
            }
        }
        
        cout << total << '\n';
        for(ll l = 0; l < anos.size(); l++)
            cout << anos[l] << ' ';
        cout << '\n';

        total = 0;
        v.clear();
        anos.clear();
        c.clear();
    }
}