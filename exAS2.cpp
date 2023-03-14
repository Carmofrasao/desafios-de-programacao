#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0); ios::sync_with_stdio(0);

    // code 

    ll n = 0;
    while(cin >> n){
        short lifo = 1;
        short fifo = 1;
        short priority = 1;
        stack<int> fila_l;
        queue<int> fila_f;
        priority_queue <int> fila_p;
        
        for(int i = 0; i < n; i++){
            int aux;
            int aux2; 
            cin >> aux;
            cin >> aux2;
            if(aux == 0){
                fila_l.push(aux2);
                fila_f.push(aux2);
                fila_p.push(aux2);
            }
            else{
                if(fila_l.top() == aux2 && lifo >= 0){
                    fila_l.pop();
                    lifo = 1;
                }
                else{
                    lifo = -1;
                }
                if(fila_f.front() == aux2 && fifo >= 0){
                    fila_f.pop();
                    fifo = 1;
                }
                else{
                    fifo = -1;
                }
                if(fila_p.top() == aux2 && priority >= 0){
                    fila_p.pop();
                    priority = 1;
                }
                else{
                    priority = -1;
                }
            }
        }

        if(n == 2){
            fifo = 1;
            priority = 1;
            lifo = 1;
        }

        if(priority == 1 && (lifo == 1 || fifo == 1)){
            cout << "ambiguous\n";
        }
        else if (lifo == 1){
            cout << "lifo\n";
        }
        else if (fifo == 1){
            cout << "fifo\n";
        }
        else if(priority == 1){
            cout << "priority\n";
        }
        else{
            cout << "unknown\n";
        }
    }
}