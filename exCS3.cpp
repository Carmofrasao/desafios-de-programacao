#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define vull vector<ull>

void combinacoes(vector<ull> const &arr, ull i, ull k, vector<ull> & sub, vector<ull> & add, vector<ull> & aux)
{
    if (arr.size() == 0 || k > arr.size())
        return;
 
    if (k == 0) 
    {
        ull mult = 1;
        for(ull i = 0; i < aux.size(); i++)
        {
            mult *= aux[i];
        }
        if(aux.size() % 2 == 0)
            add.push_back(mult);
        else
            sub.push_back(mult);
        return;
    }
 
    for (ull j = i; j < arr.size(); j++)
    {
        aux.push_back(arr[j]);
        combinacoes(arr, j + 1, k - 1, sub, add, aux);
        aux.pop_back();
    }
}

int main(int argc, char const *argv[])
{
    ull inicio, fim, tam_primos, resposta, tam;
    vector<ull> aux, sub, add;

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> inicio >> fim >> tam_primos;
    resposta = tam = (fim - inicio) + 1;
    //cout << tam << " = tam\n";
    vull primos(tam_primos);

    for(ull i = 0; i <= tam_primos; i++)
        cin >> primos[i];

    for(ull k = 0; k <= (primos.size() - 1); k++)
        combinacoes(primos, 0, k + 1, sub, add, aux);

    for(ull i = 0; i < sub.size(); i++)
        resposta -= (fim/sub[i]) - ((inicio - 1)/sub[i]);

    for(ull i = 0; i < add.size(); i++)
        resposta += (fim/add[i]) - ((inicio - 1)/add[i]);

    cout << resposta << "\n";
}