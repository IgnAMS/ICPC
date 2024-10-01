#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)


int DP[100+1][900+1];
int DP2[100+1][900+1];

vector<bool> D,D2;
vector<int> ans,ans2;

int dpmini(int m, int s){
    if(s<0) return 0;
    if(DP[m][s]!=-1) return DP[m][s];

    if(m*9 < s) return DP[m][s]=0;
    if(m==0 && s!=0) return DP[m][s]=0;

    if(m==0 && s==0) return DP[m][s]=1;

    for(int i=0;i<10;i++){
        if(dpmini(m-1,s-i) == 1){
            if(!D[m]){
                ans.push_back(i);
                D[m]=true;
            }
            return DP[m][s]=1;
        }
    }
    return DP[m][s]=0;
}

int dpmaxi(int m, int s){
    if(s<0) return 0;
    if(DP2[m][s] != -1) return DP2[m][s];

    if(m*9 < s) return DP2[m][s]=0;
    if(m==0 && s!=0) return DP2[m][s]=0;

    if(m==0 && s==0) return DP2[m][s]=1;

    for(int i=9;i>=0;i--){
        if(dpmaxi(m-1,s-i) == 1){
            if(!D2[m]){
                ans2.push_back(i);
                D2[m]=true;
            }
            return DP2[m][s]=1;
        }
    }
    return DP2[m][s]=0;
}


int main(){
    int m,s; cin>>m>>s;
    memset(DP,-1,sizeof(DP));
    memset(DP2,-1,sizeof(DP));

    if(s==0 && m==1){
        cout<<0<<" "<<0<<endl;
        return 0;
    }
    else if(s==0 && m>1 || 9*m < s){
        cout<<-1<<" "<<-1<<endl;
        return 0;
    }
    D.assign(m,false);
    D2.assign(m,false);

    for(int i=1;i<10;i++){
        if(dpmini(m-1,s-i)==1){
            ans.push_back(i);
            break;
        }
    }
    for(int i=9;i>=1;--i){
        if(dpmaxi(m-1,s-i)==1){
            ans2.push_back(i);
            break;
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto x: ans) cout<<x;
    cout<<" ";
    
    reverse(ans2.begin(),ans2.end());
    for(auto x: ans2) cout<<x;
    cout<<endl;



    return 0;
}