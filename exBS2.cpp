#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0); ios::sync_with_stdio(0);

    // code 
    
    ll n = 0;

    cin >> n;
        int altura[n];
        char direcao[n];
        bool ligado[n];
        bool possivel = false;
        for(int i = 0; i < n; i++){
            cin >> altura[i];
            cin >> direcao[i];
        }
        for (int i = 0; i < n; i++){
            ligado[i] = false;
        }
        

        int i = 0;
        while(i < n){
            if(direcao[i] == 'L'){
                int l = i+1;
                while(l < n && altura[i] >= altura[l]){
                    if(direcao[l] == 'O'){
                        if(altura[i] < altura[l]){
                            continue;
                        }
                        else if(altura[i] == altura[l]){
                            ligado[i] = true;
                            ligado[l] = true;
                            // cout << "LIGOU " << i << ' ' << l << '\n';
                        }
                        else if(altura[i] < altura[l]){
                            i = l;
                            break;
                        }
                    }
                    else if (altura[l] >= altura[i]){
                        break;
                    }
                    l++;
                    // cout << i << ' ' << l << '\n';
                }
            }
            i++;
        }
        
        for (int i = 0; i < n; i++){
            if(ligado[i] == true)
                possivel = true;
            else{
                possivel = false;
                break;
            }
        }

        if(possivel){
            cout << "S\n";
        }
        else{
            cout << "N\n";
        }
    
}
