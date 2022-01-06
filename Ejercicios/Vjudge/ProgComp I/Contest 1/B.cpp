#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string line;
    while(getline(cin,line)){
        vector<int> A;
        int c=0;
        ll suma=0;
        bool neg=0;
        for(int i=0;i<line.length();i++){
            if(line[i]==' ') { A.push_back(neg? -c:c); neg=0; c=0; continue; }
            if(line[i]=='-') neg=1;
            else c= c*10 + line[i]-'0';
        }
        A.push_back(neg? -c:c);
        rep(i,A.size()) suma+=A[i];
        rep(i,A.size()) if(suma-A[i]==A[i]) { cout<<A[i]<<"\n"; break; } 


    }




    return 0;
}