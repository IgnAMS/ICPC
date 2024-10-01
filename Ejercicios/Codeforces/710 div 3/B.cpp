#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        string s; cin>>s;
        int cont=0;
        deque<int> dq; //me guarda la posicion
        int last=0;
        rep(i,n) if(s[i]=='*') last=i;
        rep(i,n){
            if(s[i]=='*' && dq.empty()) dq.push_back(i);
            else if(s[i]=='*' && dq.size()==1) dq.push_back(i);
            else if(s[i]=='*'){
                int j=dq.size()-1;
                //cout<<"aaa\n";
                while(dq.size()>=2 && i-dq[j-1]<=k){
                    //cout<<"elimino el elemento "<<dq.back()<<"\n";
                    j--;
                    dq.pop_back();
                }
                dq.push_back(i);
            }
        }
        cout<<dq.size()<<"\n";
    }





    return 0;
}