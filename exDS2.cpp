#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0); ios::sync_with_stdio(0);

    // code 
    ll n = 0;

    while(cin >> n){
        ll k = 0;
        cin >> k;
        string descricoes[2*n];
        bool marca[2*n];
        for (ll i = 0; i < 2*n; i++){
            descricoes[i] = '\0';
            cin >> descricoes[i];
            marca[i] = false;
        }

        ll cont = 1;
        ll max = 1;
        ll i = 0;
        while(i < 2*n && max < n/2){
            for (ll l = i+1; l < 2*n; l++){
                if(marca[i] == true) break;
                else if(descricoes[i] == descricoes[l] && marca[l] == false){
                    marca[i] = true;
                    marca[l] = true;
                    if(cont > max) max = cont; 
                    cont--;
                    break;
                }
                else if(descricoes[i] != descricoes[l] && marca[l] == false){
                    cont++;
                    if(cont > max) max = cont; 
                }
            }
            
            cont = 1;
            i++;
        }
        
        // ll cont = 0;
        // ll max = 1;
        // ll i = 0;
        // while(i+1 < 2*n){
        //     if(descricoes[i] == descricoes[i+1] && marca[i] != true && marca[i+1] != true){
        //         marca[i] = true;
        //         marca[i+1] = true;
        //         i = i+2;
        //         cont = 0;
        //     }
        //     else if(marca[i] != true && marca[i+1] != true){
        //         ll a = i+1;
        //         while(a < 2*n && descricoes[i] != descricoes[a]){
        //             cont++;
        //             a++;
        //         }
        //         if(a < 2*n && descricoes[i] == descricoes[a]){
        //             marca[i] = true;
        //             marca[a] = true;
        //         }
        //         i++;
        //     }
        //     else{
        //         i++;
        //     }
        //     if(cont > max) max = cont; 
        //     cont = 0;
        //     if(max >= n/2){
        //         break;
        //     }
        // }
        if(n == 0){
            cout << "3.14159\n";
        }
        else if (max >= k){
            cout << "7.18808\n";
        }
        else{
            cout << "3.14159\n";
        }
    }
}