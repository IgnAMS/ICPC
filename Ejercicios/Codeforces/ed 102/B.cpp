#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        string a, b;
        cin>>a>>b; //a siempre será el chico
        if(a.length()>b.length()) swap(a,b);
        int an=a.length(), bn=b.length();
        bool oc=1;
        string aux1="", aux2="";
        for(int i=0;i<bn/__gcd(an,bn);i++) aux1+=a;
        for(int i=0;i<an/__gcd(an,bn);i++) aux2+=b;
        if(aux1==aux2) cout<<aux1<<"\n";
        else cout<<-1<<"\n";
        
    }


    return 0;
}