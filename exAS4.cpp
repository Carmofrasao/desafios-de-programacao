#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

ull maior_lucro(ull pao, ull hamburguer, ull frango, ull cheddar, ull c)
{
    ull qtd_sand = pao/2, sum = 0;
    ull h = hamburguer, f = frango;
    bool prioChed = false;
    if(cheddar > c)
        prioChed = true;

    if(qtd_sand > 0)
    {
        for(ull i = 0; i < qtd_sand; i++)
        {
            if(prioChed)
            {
                if(h > 0)
                {
                    sum += cheddar;
                    h--;
                }
                else if (f > 0)
                {
                    sum += c;
                    f--;
                }
            }
            else
            {
                if(f > 0)
                {
                    sum += c;
                    f--;
                }
                else if(h > 0)
                {
                    sum += cheddar;
                    h--;
                }
            }
        }
        return sum;
    }
    else
        return 0;
}

int main() 
{
    ull casos_teste, pao, hamburguer, frango, cheddar, c;

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> casos_teste;

    for(ull i = 0; i < casos_teste; i++)
    {
        cin >> pao >> hamburguer >> frango >> cheddar >> c;
        cout << maior_lucro(pao, hamburguer, frango, cheddar, c) << "\n";
    }
}