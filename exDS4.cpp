#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;

// g++ -static -std=c++11 -O2 -Wall -g first.cpp

int main() {
    cin.tie(0); ios::sync_with_stdio(0);

    // code 

    auto t = 0;

    while(cin >> t){
        for(auto z = 0; z < t; z++){
            string s;
            cin >> s;
            ll i = 0; 
            auto guarda = 0;
            while(i < s.size()){
                if(s[i] == '_'){
                    guarda++;
                    i+=3;
                }
                else
                    i++;
            }
            cout << "Caso " << z+1 << ": " << guarda << '\n';
            guarda = 0;
        }  
    }
}