#include<bits/Stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    map<string,int> ans;
    int c=0, cont=0;
    for(int i=1;i<=9;i++){
        c=1;
        string linea="";
        linea+=char(i+'0');
        while(linea.length()<=4){
            cont+=c;
            //cout<<linea<<" "<<cont<<"\n";
            ans.insert({linea,cont});
            c++;
            linea+=char(i+'0');
        }
    }

    int t; cin>>t; 
    while(t--){
        string n; cin>>n;
        cout<<ans[n]<<"\n";
    }





    return 0;
}