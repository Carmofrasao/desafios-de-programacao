#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n = 0;
    vector <char> rna;
    ll ea1 = 0;
    ll ea2 = 0;
    int as1 = 0;
    int as2 = 0;
    bool marca = false;

    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            rna.push_back(0);
            cin >> rna.at(i);
        }

        for (int i = 0; i < n; i++)
        {
            if(rna.at(i) == 'A' && marca == false){
                ea1 = i;
                marca = true;
                as1 += 1;
            }
            else if(rna.at(i) == 'A' && marca == true){
                as1 += 1;
            }
            else if(rna.at(i) != 'A' && as1 < 7){
                ea1 = 0;
                as1 = 0;
                marca = false;
            }
            if(as1 >= 7){
                break;
            }
        }
        marca = false;
        for (int i = n-1; i >= 0; i--)
        {
            if(rna.at(i) == 'A' && marca == false){
                ea2 = i;
                as2 += 1;
                marca = true;
            }
            else if(rna.at(i) == 'A' && marca == true){
                as2 += 1;
            }
            else if(rna.at(i) != 'A' && as2 < 7){
                ea2 = 0;
                as2 = 0;
                marca = false;
            }
            if(as2 >= 7){
                break;
            }
        }

        if(as1 >= 7 && as2 >= 7 && ea2 > ea1 && ea2 - ea1 + 1 >= 7){
            cout << ea2 - ea1 + 1 << '\n';
        }
        else{
            cout << '0' << '\n';
        }
        ea1 = 0;
        ea2 = 0;
        marca = false;
        as1 = 0;
        as2 = 0;
    }
}