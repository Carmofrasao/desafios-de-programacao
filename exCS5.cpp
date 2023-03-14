#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0); ios::sync_with_stdio(0);

    ll n;
    while (cin >> n){
        vector<ll>a;
        ll aux, m;
        vector<ll>aux1;
        for (ll i = 0; i < n; i++){
            cin >> aux;
            a.push_back(aux);
            aux = 0;
            for (ll l = 0; l <= i; l++){
                aux+=a[l];
            }
            aux1.push_back(aux);
        }
        cin >> m;
        for (ll l = 0; l < m; l++){
            cin >> aux;
            for (ll i = 0; i < n; i++){
                if(aux <= aux1[i]){
                    cout << i+1 << '\n';
                    break;
                }
            }
        }
    }
}