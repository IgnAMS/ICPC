#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int x, y;
vector<int> C(8);


void backtracking(int col, vector<vector<int>>& ans){
    if(col==y){
        //no funciona
        rep(i,col) if(abs(C[i]-x) == abs(i-y) || C[i]==x) return;
        C[y]=x;
        if(y==7){
            //pusheo si es solucion
            ans.push_back(C);
            return;
        }
        backtracking(col+1, ans);
        //termine este caso         
        return;
    }

    if(col==7){
        rep(j, 8){
            bool flag=1;
            rep(i,col) if(abs(C[i]-j) == abs(i-col) || j==C[i]) flag=0;
            C[col]=j;
            //pusheo si es solucion
            if(flag) ans.push_back(C);
        } 
        return;
    }

    rep(j, 8){
        C[col] = j;
        bool flag=1;
        rep(i,col) if(abs(C[i]-j) == abs(i-col) || j==C[i]) flag=0;
        if(flag) backtracking(col+1, ans);
    } 
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    rep(_, t){
        cin>>x>>y; x--, y--;
        C[x]=y;
        vector<vector<int>> ans;
        backtracking(0, ans);
        cout<<"SOLN       COLUMN\n";
        cout<<" #      1 2 3 4 5 6 7 8\n\n";
        rep(i, ans.size()){
            auto& u = ans[i];
            if(i+1<10) cout<<" "<<i+1<<"      ";
            else cout<<i+1<<"      ";
            rep(j,8) cout<<u[j]+1<<(j<7? " ":"");
            cout<<"\n";
        }
        
        if(_<t-1) cout<<"\n";

    }


    return 0;
}