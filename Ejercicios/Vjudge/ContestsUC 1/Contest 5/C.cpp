#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ff first
#define ss second

typedef pair<int,int> ii;
vector<vector<ii>> ans;
vector<ii> aux; //row, column
bool col[10];
int ini;
bool checkdiag(int r, int c){
    for(auto x: aux){
        if(abs(x.ff-r)==abs(x.ss-c)) return false;
    }
    return true;
}

void backtrack(int r){
    if(r==8){
        ans.push_back(aux);
        return;
    }
    if(r==ini) { backtrack(r+1); return;}
    rep(c,8) if(!col[c] && checkdiag(r,c)) {
        col[c]=true;
        aux.push_back(ii(r,c));
        
        backtrack(r+1);
        
        col[c]=false;
        aux.pop_back();
    }
    return;
}


int main(){
    int t; cin>>t;
    while(t--){
        int r,c; cin>>r>>c;
        ans.clear();
        aux.clear();
        r--, c--;
        ini=r;
        aux.push_back(ii(r,c));
        memset(col,0,sizeof(col));
        col[c]=true;
        backtrack(0);

        rep(i,ans.size()){
            sort(ans[i].begin(),ans[i].end(),[&](const ii &a, const ii &b){
                return a.ss<b.ss;
            });
        }

        sort(ans.begin(),ans.end(),[&](const vector<ii> &a, const vector<ii> &b){
            int ind=0;
            while(ind<8 && a[ind]==b[ind]) ind++;
            return a[ind]<b[ind];
        });

        cout<<"SOLN       COLUMN"<<endl<<" #      1 2 3 4 5 6 7 8"<<endl<<endl;
        //reverse(ans.begin(),ans.end());
        for(int j=0;j<ans.size();j++){
            vector<ii> &x=ans[j];
            if(j+1<10) cout<<' ';
            cout<<j+1<<"      ";
            for(int i=0;i<x.size();i++){
                cout<<x[i].ff+1;
                if(i<x.size()-1) cout<<" ";
            }
            cout<<endl;
        }
        if(t>=1) cout<<endl;
    }



    return 0;
}