#include <bits/stdc++.h>

using namespace std;

using ull =  unsigned long long;

typedef struct {
    ull a;
    ull b;
}var;

ull sz;
ull ln;

ull fast_pow(ull a, ull b) 
{
  if (b == 0) { return 1; } if (b == 1) { return a; }
  ull res = fast_pow(a, b/2);
  res = (res * res) % 1000000007;
  if (b % 2) res = (res * a) % 1000000007;
  return res;
}

int main() {

  ull i;
  vector<ull> mx;
  vector<var>cor;

  while(cin >> sz){
    cin >> ln;
          
    ull aux = 0;
    ull max = 0;
    for (i = 0; i < sz; i++){
      cin >> aux;
      mx.push_back(aux);
      if(aux > max) max = aux;
    }

    ull vFat[max+1];
    vFat[0] = 1;
    for(ull i = 1; i < (max + 1); i++){
      vFat[i] = i * vFat[i - 1];
      vFat[i] %= 1000000007;
    }

    vector<ull>sol;

    var aux1;
    for (i = 0; i < ln; i++){
      cin >> aux1.a;
      cin >> aux1.b;
      cor.push_back(aux1);
    }

    ull fact = 1;
    for (i = 0; i < mx.size(); i++){
      ull curr_r = sz;
      for(ull g = 0; g < ln; g++){
        if (cor[g].b-1 == i ){
          curr_r--;
        }
      }
      fact = vFat[mx[i]]*fast_pow(vFat[mx[i]-curr_r], 1000000005);
      fact %= 1000000007;
      sol.push_back(fact);
    }
    fact = 1;
    for (ull i = 0; i < sol.size(); i++){
      fact *= sol[i];
      fact %= 1000000007;
    }
    
    cout << fact << "\n";
    mx.clear();
    cor.clear();
  }
}