#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string num;
    int a = 0;
    int b = 0;
    int n = 0;
    int l;
    cin >> n >> ws;
    for(int i = 0; i < n; i++){
        getline(cin, num);
        cout << num << '\n';
        l = 0;
        while (num[l] != ' '){
            a = num[l] - '0';
            l++;
        }
        b = num[num.size() - 1] - '0';
        cout << a << '-' << b << '\n';
        if(a % 2 == b % 2){
            cout << "PARCEIROS\n";
        }
        else{
            cout << "NAO PARCEIROS\n";
        }
    }
}