#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    ll erro = 0;

    vector<ll> a;
    vector<ll> aux;
    vector<ll> b;
    
    while (cin >> n)
    {
        for(int i = 0; i < n; i++){
            a.push_back(0);
            cin >> a.at(i);
        }
        for (int i = 0; i < n/2; i++){
            b.push_back(0);
            cin >> b.at(i);
        }

        for (int i = 0; i < n/2; i++){
            aux.push_back(0);
            aux.at(i) = a.at(i) + a.at(n-i-1);
        }
        
        for (int i = 0; i < n/2; i++){
            if(b.at(i) != aux.at(i)){
                erro += abs(aux.at(i)-b.at(i));
            }
        }
        cout << erro << '\n';

        erro = 0;
    }
}