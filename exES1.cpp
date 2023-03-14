#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n = 0;
    ll v = 0;

    cin >> n;
    cin >> v;
    ll vo = 0;
    bool impar = false;

    vector <ll> vagas;
    for (int i = 0; i < n; i++){
        vagas.push_back(0);
        vagas.at(i) = 0;
    }
    
    ll i = 1;
    string nome;
    string hora;
    int num;
    ll classificacao;

    for (int i = 0; i < n; i++)
    {
        cin >> nome;
        cin >> hora;
        cin >> num;
        cin >> classificacao;
    }

    vector<ll>sec;
    if(n == 1){
        sec.push_back(0);
        sec.at(0) = 1;
        vo+=1;
    }
    else{
        while(i < n){
            vagas.at(i) = 1;
            sec.push_back(0);
            sec.at(vo) = i+1;
            vo += 1;
            
            if(n % 2 == 0 && vagas.at(n-1) == 1 && impar == false){
                i = 0;
                impar = true;
            }
            else if(n % 2 != 0 && vagas.at(n-2) == 1 && impar == false){
                i = 0;
                impar = true;
            }
            else{
                i+=2;
            }
            if(vo >= v){
                break;
            }
        }
    }
    for (int i = 0; i < vo; i++){
        cout << sec.at(i) << '\n';
    }
}