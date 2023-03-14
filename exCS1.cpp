#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string materia;
    int horas = 0;
    int min = 0;

    while (cin >> materia)
    {
        cin >> horas;
        cin >> min;
        
        if (horas*60+min > 600){
            cout << "Abel deve cancelar " << materia << '\n';
        }
        else{
            cout << "Abel deve cursar " << materia << '\n';
        }
    }
}