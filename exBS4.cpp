#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll moeda[(ll)(3 * 10e4 + 1)][5];

ll collect(ll c[], ll m, ll n)
{
    ll in, ex;
    for(ll i = 0; i < m; i++)
        moeda[0][i] = 1;
    for(ll i = 1; i < n + 1; i++)
    {
        for(ll j = 0; j < m; j++)
        {
            in = (i-c[j] >= 0) ? moeda[i - c[j]][j] : 0;
            ex = (j >= 1) ? moeda[i][j - 1] : 0;
            moeda[i][j] = in + ex;
        }
    }
    return moeda[n][m - 1];
}

int main(int argc, char const *argv[])
{
    ll n;
    ll c[] = {1, 5, 10, 25, 50};
    ll m = 5;

    collect(c, m, (ll)(3 * 10e4));

    while(cin >> n)
    {
        cout << moeda[n][m - 1] << "\n";
    }
}