#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;

int main(){

    ll r, p, k, x;
    ll n;
    ll damage;

    cin >> n >> x >> r >> p >> k;

    damage = n*x;

    string s;
    cin >> s;

    vector<bool> isPoison(n, false);
    ll tcomp;
    ll rcomp;

    ll pos = 0; //regen strings
    ll t = 0; //first turn
    if(k > n){
        k = n;
    }
    while(k > 0 and pos < n){
        if(s[pos] != '1' or isPoison[pos]){
            pos++;
            continue;
        }
        if(isPoison[t]){
            t++;
            continue;
        }
        tcomp = (n-t)*p;
        rcomp = (n-pos)*(p+r);
        //cout << tcomp << " " << rcomp << " " << t << " " << pos << endl;
        if(tcomp >= rcomp){
            isPoison[t] = true;
            damage += (n-t)*p;
            t++;
        }
        else{
            isPoison[pos] = true;
            damage += (n-pos)*p;
            pos++;
        }
        k--;
    }
    while(k > 0 and t < n){
        if(isPoison[t]){
            t++;
        }
        else{
            isPoison[t] = true;
            damage += (n-t)*p;
            t++;
            k--;
        }
    }
    for(ll z = 0; z < n; z++){
        if(s[z] == '1' and !isPoison[z]){
            damage -= r*(n-z);
        }
    }
    cout << damage << endl;
    /*for(bool b : isPoison){
        cout << b;
    }
    cout << '\n' << s << endl;*/
    
    return 0;

}