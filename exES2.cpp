#include <bits/stdc++.h>

using namespace std;
using ll = long long;

typedef struct{
    string especialidade;
    int h;
    int m;
    int a;
    ll c;
}concorre;

vector<concorre> vet;
vector<ll> concorrente;

int main() {
    cin.tie(0); ios::sync_with_stdio(0);

    // code 

    ll n, v;
    cin >> n >> v;
    
    string delimitador = ":";
    size_t pos;
    ll ocupaVaga = 0;
    
    for (ll i = 0; i < n; i++){
        concorre aux2;
        string aux;
        cin >> aux2.especialidade >> aux >> aux2.a >> aux2.c;
        pos = aux.find(delimitador);
        aux2.h = stoi(aux.substr(0, pos));
        aux.erase(0, pos + delimitador.length());
        aux2.m = stoi(aux);
        vet.push_back(aux2);
        if(vet[i].especialidade == "idjassu" || vet[i].especialidade == "galhofa" || vet[i].especialidade == "aipenkuit"){
            concorrente.push_back(-1);
            concorrente.at(ocupaVaga) = i;
            ocupaVaga++;
        }
    }

    sort(concorrente.begin(), concorrente.end(), [](ll a, ll b){
        if(vet[a].h < 13 && vet[b].h >= 13){
            return false;
        }  
        else if(((vet[a].h >= 13 && vet[b].h >= 13) || (vet[a].h < 13 && vet[b].h < 13)) && vet[a].a < vet[b].a){
            return false;
        }  
        else if(((vet[a].h >= 13 && vet[b].h >= 13) || (vet[a].h < 13 && vet[b].h < 13)) && vet[a].a == vet[b].a && vet[a].c > vet[b].c){
            return false;
        }
        return true;
    });

    if(ocupaVaga < v){
        ll ocupaVagaN = ocupaVaga;

        for (ll i = 0; i < n; i++){
            if(vet[i].especialidade != "idjassu" && vet[i].especialidade != "galhofa" && vet[i].especialidade != "aipenkuit"){
                concorrente.push_back(-1);
                concorrente.at(ocupaVagaN) = i;
                ocupaVagaN++;
            }
        }
        
        sort(concorrente.begin()+ocupaVaga, concorrente.end(), [](ll a, ll b){
            if(vet[a].h < 13 && vet[b].h >= 13){
                return false;
            }  
            else if(((vet[a].h >= 13 && vet[b].h >= 13) || (vet[a].h < 13 && vet[b].h < 13)) && vet[a].a < vet[b].a){
                return false;
            }  
            else if(((vet[a].h >= 13 && vet[b].h >= 13) || (vet[a].h < 13 && vet[b].h < 13)) && vet[a].a == vet[b].a && vet[a].c > vet[b].c){
                return false;
            } 
            return true;
        });
    }
    
    for (ll i = 0; i < v; i++){
        cout << concorrente.at(i)+1 << '\n';   
    } 
}

// #include <bits/stdc++.h>

// using namespace std;
// using ll = long long;

// typedef struct{
//     string especialidade;
//     int h;
//     int m;
//     int a;
//     ll c;
// }concorrente;

// int main() {
//     cin.tie(0); ios::sync_with_stdio(0);

//     // code 

//     ll n, v;
//     cin >> n >> v;
    
//     concorrente vet_concorre[n];
//     string delimitador = ":";
//     size_t pos;
//     ll ocupaVaga = 0;
//     ll concorrente[n];
//     for (int i = 0; i < n; i++){
//         string aux;
//         cin >> vet_concorre[i].especialidade >> aux >> vet_concorre[i].a >> vet_concorre[i].c;
//         pos = aux.find(delimitador);
//         vet_concorre[i].h = stoi(aux.substr(0, pos));
//         aux.erase(0, pos + delimitador.length());
//         vet_concorre[i].m = stoi(aux);
//         concorrente[i] = -1;
//         if(vet_concorre[i].especialidade == "idjassu" || vet_concorre[i].especialidade == "galhofa" || vet_concorre[i].especialidade == "aipenkuit"){
//             concorrente[ocupaVaga] = i;
//             ocupaVaga++;
//         }
//     }

//     for (int i = 0; i < ocupaVaga; i++){
//         for (int l = i+1; l < ocupaVaga; l++){
//             if(vet_concorre[concorrente[i]].h < 13 && vet_concorre[concorrente[l]].h >= 13){
//                 swap(concorrente[i], concorrente[l]);
//             }  
//             else if(((vet_concorre[concorrente[i]].h >= 13 && vet_concorre[concorrente[l]].h >= 13) || (vet_concorre[concorrente[i]].h < 13 && vet_concorre[concorrente[l]].h < 13)) && vet_concorre[concorrente[i]].a < vet_concorre[concorrente[l]].a){
//                 swap(concorrente[i], concorrente[l]);
//             }  
//             else if(((vet_concorre[concorrente[i]].h >= 13 && vet_concorre[concorrente[l]].h >= 13) || (vet_concorre[concorrente[i]].h < 13 && vet_concorre[concorrente[l]].h < 13)) && vet_concorre[concorrente[i]].a == vet_concorre[concorrente[l]].a && vet_concorre[concorrente[i]].c > vet_concorre[concorrente[l]].c){
//                 swap(concorrente[i], concorrente[l]);
//             }
//         }
//     }
    
//     if(ocupaVaga < v){
//         ll ocupaVagaN = ocupaVaga;

//         for (int i = 0; i < n; i++){
//             if(vet_concorre[i].especialidade != "idjassu" && vet_concorre[i].especialidade != "galhofa" && vet_concorre[i].especialidade != "aipenkuit"){
//                 concorrente[ocupaVagaN] = i;
//                 ocupaVagaN++;
//             }
//         }
        
//         for (int i = ocupaVaga; i < ocupaVagaN; i++){
//             for (int l = i+1; l < ocupaVagaN; l++){
//                 if(vet_concorre[concorrente[i]].h < 13 && vet_concorre[concorrente[l]].h >= 13){
//                     swap(concorrente[i], concorrente[l]);
//                 }  
//                 else if(((vet_concorre[concorrente[i]].h >= 13 && vet_concorre[concorrente[l]].h >= 13) || (vet_concorre[concorrente[i]].h < 13 && vet_concorre[concorrente[l]].h < 13)) && vet_concorre[concorrente[i]].a < vet_concorre[concorrente[l]].a){
//                     swap(concorrente[i], concorrente[l]);
//                 }  
//                 else if(((vet_concorre[concorrente[i]].h >= 13 && vet_concorre[concorrente[l]].h >= 13) || (vet_concorre[concorrente[i]].h < 13 && vet_concorre[concorrente[l]].h < 13)) && vet_concorre[concorrente[i]].a == vet_concorre[concorrente[l]].a && vet_concorre[concorrente[i]].c > vet_concorre[concorrente[l]].c){
//                     swap(concorrente[i], concorrente[l]);
//                 } 
//             }
//         }
//     }
    
//     for (int i = 0; i < v; i++){
//         cout << concorrente[i]+1 << '\n';   
//     } 
// }