#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

vector<int> col(8);

int mini=9;
bitset<16> ld, rd, rw; 
void backtrack(int x, int sum){
    if(x==8){
        //cout<<sum<<"\n";
        mini=min(sum,mini);
        return;
    }
    for(int i=0;i<8;i++){
        if(!rw[i] && !ld[7+i-x] && !rd[i+x]){
            //cout<<"col: "<<x<<", row: "<<i<<"\n";
            rw[i] = ld[7+i-x] = rd[i+x] = 1;
            backtrack(x+1, sum+(i==col[x]? 0:1));
            rw[i] = ld[7+i-x] = rd[i+x] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int cas=0;
    while(cin>>col[0] && ++cas){
        rep(i,7) cin>>col[i+1];
        rep(i,8) col[i]--;
        mini=9;
        backtrack(0,0);
        cout<<"Case "<<cas<<": ";
        cout<<mini<<"\n";

    }




    return 0;
}