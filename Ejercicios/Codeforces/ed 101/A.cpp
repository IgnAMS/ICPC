#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        string linea; cin>>linea;
        int n=linea.length();
        int a=0,b=0,c=0;
        bool flag=1;
        if(n%2!=0) flag=0;
        rep(i,n){
            if(linea[i]=='(') a++;
            if(linea[i]==')') b++;
            if(linea[i]=='?') c++;
            if(a+c-b<0) flag=0; //chequeo que no haya )....
        }
        int a2=0,b2=0,c2=0;
        rep(i,n){
            if(linea[n-i-1]=='(') a2++;
            if(linea[n-i-1]==')') b2++;
            if(linea[n-i-1]=='?') c2++;
            if(b2+c2-a2<0) flag=0;
        }
        if(abs(a-b)>c) flag=0; //chequeo que se puedan cerrar todos
        cout<<(flag? "YES\n":"NO\n");

    }



    return 0;
}