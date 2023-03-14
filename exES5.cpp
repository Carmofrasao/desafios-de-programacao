#include <bits/stdc++.h>

using namespace std;
using ll = long double;

// g++ -static -std=c++11 -O2 -Wall -g first.cpp

int main() {
    cin.tie(0); ios::sync_with_stdio(0);

    // code 
    
    ll a, b, c;
    while (cin >> a){
        cin >> b >> c;
        auto aux = sqrt(b*b - 4*a*c);
        long long aux1 = aux;
        if(aux == aux1){
            cout << "Y\n";
        }
        else{
            cout << "N\n";
        }
    }
}