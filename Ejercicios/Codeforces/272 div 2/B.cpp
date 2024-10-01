#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;



int main(){
    cout.precision(9);
    ll C[12][12];
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            C[i][i]=1;
            C[i][0]=1;
        }
    }
    for(int i=2;i<12;i++){
        for(int j=1;j<i;j++){
            C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
    }
    string linea; cin>>linea;
    string linea2; cin>>linea2;
    int contp=0, contn=0;
    int p=0,n=0;
    int q=0;
    for(auto j:linea) j=='+'? p++:n++;
    for(auto j:linea2){
        if(j=='+') contp++;
        else if(j=='-') contn++;
        else q++;
    }
    if(contp>p || contn>n){
        cout<<0<<endl;
        return 0;
    }
    if(contp==p && contn==n){
        cout<<1<<endl;
        return 0;
    }
    ll casosT=0;
    ll casosB=C[q][p-contp];
    for(int i=0;i<=q;i++){
        casosT+=C[q][i];
    }
    cout<<setprecision(11)<<fixed<<double(casosB)/double(casosT)<<endl;
    //cout<<casosB<<" / "<<casosT<<endl;
    



    return 0;
}