#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

string ans="123";
vector<string> A, B;
vector<bool> V;

int n;

bool check(string a, string b){
    return a.size()==b.size() && a==b && (ans=="123" || (ans!="123" && (a.size()<ans.size() || (a.size()==ans.size() && a<ans))));
}


void backtrack(string a, string b){
    if(check(a,b) && a!=""){
        ans=a;
        return;
    }
    rep(i,n){
        if(!V[i]){
            V[i]=1;
            backtrack(a+A[i], b+B[i]);
            V[i]=0;
        }
    }

}





int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int cas=0;
    while(cin>>n){
        A.resize(n); B.resize(n); V.assign(n,0);
        rep(i,n) cin>>A[i]>>B[i];
        ans="123";
        backtrack("", "");
        cout<<"Case "<<++cas<<": ";
        if(ans=="123") cout<<"IMPOSSIBLE\n";
        else cout<<ans<<"\n";
    }


    return 0;
}