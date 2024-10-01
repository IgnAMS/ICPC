#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repx(i,a,b) for(int i=a;i<b;i++)

int palindrome(string& s, int n){
    int cont=0;
    rep(i, (n + 1)/2) if(s[i]!=s[n-1-i]) cont++;
    return cont;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cerr<<"xddd\n";
        string s; cin>>s;
        int cont_al = 0, cont_bob = 0;
        bool flag=0;
        bool rev = 0;
        bool turno = 0; // 0 es alice, 1 es bob
        rep(i,n) if(s[i] != '1') flag=1;
        while(flag){
            
            int change = palindrome(s, n);
            // si es que puedo saltar, salto
            if(change != 0 && !rev){
                rev=1;
            }
            // si es que puedo convertirlo en palindromo, lo convierto
            else if(change == 1){
                rep(i,(n+1)/2) if(s[i] != s[n-1-i]) { s[i] = '1', s[n-1-i] = '1'; break; }
                if(turno) cont_al++;
                else cont_bob++;
                rev=0;
            }
            // diferncia > 1
            // si la diferencia es 0, pero no puedo voltear
            else{
                rep(i, (n+1)/2) if(s[i] != s[n-1-i]) { s[i] = '1', s[n-1-i] = '1'; break; }
                if(turno) cont_al++;
                else cont_bob++;
                rev=0;
            }
            
            turno = !turno;
            flag = 0;
            rep(i,n) if(s[i] != '1') flag=1;
        }
        cerr<<cont_al<<" "<<cont_bob<<"\n";
        cout<<cont_al<<" "<<cont_bob<<"\n";
    }




    return 0;
}
