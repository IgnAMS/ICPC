#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n; i++)
typedef pair<string,string> ss;

vector<string> a,b;
int m;
vector<bool> D;
string ans="A";
int n;

bool check(int s1, int s2, int s11, int s22){
    return (ans=="A" || (ans!="A" && s1+s11<=m && s2+s22<=m));  
}


void backtrack(string s1, string s2){
    if(s1==s2 && s1!="" && s1.size()<=m){
        if(s1.size()==m && s1 < ans) ans=s1;
        if(s1.size()<m) ans=s1;
        m=ans.size();
        //cout<<"encontre una respuesta: "<<ans<<endl;
        return;
    }
    //cout<<s1<<" "<<s2<<endl;
    rep(h,n) if(!D[h] && check(s1.size(),s2.size(),a[h].size(),b[h].size())){
        D[h]=true;
        s1.append(a[h]);
        s2.append(b[h]);
        backtrack(s1,s2);
        s1.erase(s1.size()-a[h].size(),a[h].size());
        s2.erase(s2.size()-b[h].size(),b[h].size());
        D[h]=false;
    }
    return;
}



int main(){
    int t=0;
    while(cin>>n){
        t++;
        ans="A";
        a.resize(n);
        b.resize(n);
        m=1e8;
        D.assign(n,0);
        rep(i,n) cin>>a[i]>>b[i];
        backtrack("","");
        cout<<"Case "<<t<<": ";
        if(ans=="A") cout<<"IMPOSSIBLE"<<endl;
        else cout<<ans<<endl;   
    }

    //cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    
    return 0;
}   