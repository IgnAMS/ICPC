#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repx(i,a,n) for(int i=a;i<b;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    set<int> angles;
    
    rep(i,721){
        int hora = i/12;
        int minuto = i%60;
        // cout<<6 * abs(hora-minuto)<<" "<<6 * (60 - abs(minuto-hora))<<"\n";
        angles.insert(6 * min(abs(hora-minuto), 60-abs(minuto-hora)));
    }
    // for(auto& u: angles) cout<<u<<"\n";
    int a;
    while(cin>>a) cout<<(angles.count(a)? "Y\n": "N\n");

    return 0;
}