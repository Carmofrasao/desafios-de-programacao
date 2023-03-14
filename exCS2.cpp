#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main() {
    cin.tie(0); ios::sync_with_stdio(0);

    // code 

    int n = 0;

    cin >> n;
        list<ll>m;
        for (int i = 0; i < n; i++){
            ll aux = 0;
            cin >> aux;
            m.push_back(aux);
        }
        m.sort();
        ll tam = m.size();

        list<ll>::iterator tempo1 = m.begin();
        list<ll>::iterator tempo2 = m.begin();
        advance(tempo1, tam/2-1);
        advance(tempo2, tam/2);

        ll tempo = *tempo2 - *tempo1;

        cout << n/2 << ' ' << tempo << '\n';
    
}