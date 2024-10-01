#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;

int main(){
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    ll sol = 0;
    ll mult = 1;
    for(int x = 0; x < n; x++){
        if(a[x] < b[x]){
            sol += (n-x)*mult;
            mult = 0;
        }
        else if(a[x] > b[x]){
            mult = 0;
        }
        mult++;
    }

    cout << sol << endl;
    return 0;
}