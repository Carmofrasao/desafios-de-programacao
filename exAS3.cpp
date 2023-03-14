#include <bits/stdc++.h>

using namespace std;

#define ui unsigned int
#define vui vector<ui>
#define mui vector<vui>

bool check(vector<ui>& a, vector<ui>& s, vector<ui>& e)
{
    for(ui i = 0; i < s.size(); i++)
    {
        auto it1 = find(a.begin(), a.end(), s[i]);
        auto it2 = find(a.begin(), a.end(), e[i]);
        if(it1 > it2)
            return false;
    }
    return true;
}

void permutations(vector<int> & vet, vui & v, vui & s, vui & e, mui & p, int i, int n)
{
    // condição básica
    if (i == n - 1){
        for (auto x : vet) { v.push_back(x); }
        if(check(v, s, e))
            p.push_back(v);
        v.clear();
        return;
    }
 
    for (int j = i; j < n; j++)
    {
        swap(vet[i], vet[j]);        
 
        permutations(vet, v, s, e, p, i + 1, n);
 
        swap(vet[i], vet[j]);
    }
}

int main(int argc, char const *argv[])
{
    ui qtd_livros, qtd_restr, num;
    vui v, s, e;
    mui p;
    
    cin.tie(0);
    ios::sync_with_stdio(0);

    while(cin >> qtd_livros){ 
    
        cin >> qtd_restr;

        for(ui i = 0; i < qtd_restr; i++)
        {
            cin >> num;
            s.push_back(num);
            cin >> num;
            e.push_back(num);
        }

        vector<int> a (qtd_livros);
        for (ui i = 0; i < qtd_livros; i++) { a[i] = i+1; }

        permutations(a, v, s, e, p, 0, qtd_livros);

        for(ui i = 0; i < p.size(); i++)
        {
            for(ui k = 0; k < p[i].size(); k++)
            {
                cout << p[i][k] << " ";
            }
            cout << "\n";
        }
        v.clear();
        s.clear();
        p.clear();
        e.clear();
    }
}