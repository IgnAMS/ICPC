#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second

int dr[]={2,2,-2,-2,1,1,-1,-1};
int dc[]={1,-1,1,-1,2,-2,2,-2};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    //clock_t tStart = clock();
    vector<string> H= { "11111",
                        "01111",
                        "00 11",
                        "00001",
                        "00000"};
    map<vector<string>,int> D;
    D[H]=0;
    queue<vector<string>> q;
    q.push(H);
    while(!q.empty()){
        vector<string> u=q.front(); q.pop();
        int d=D[u];
        ii x;
        rep(i,5) rep(j,5) if(u[i][j]==' ') x={i,j};
        rep(h,8){
            if(0<=x.ff+dc[h] && x.ff+dc[h]<5 && 0<=x.ss+dr[h] && x.ss+dr[h]<5){
                u[x.ff][x.ss]=u[x.ff+dc[h]][x.ss+dr[h]];
                u[x.ff+dc[h]][x.ss+dr[h]]=' ';
                if(!D.count(u) && d<10){
                    q.push(u);
                    D[u]=d+1;
                }
                u[x.ff+dc[h]][x.ss+dr[h]]=u[x.ff][x.ss];
                u[x.ff][x.ss]=' ';
            }
        }
    }
    /*
    for(auto& x:D){
        cout<<"solvable in "<<x.ss<<" moves\n";
        rep(i,5) cout<<x.ff[i]<<"\n"; 
        cout<<"\n";
    }
    */
    string aux; getline(cin,aux);
    int t=0; rep(i,aux.length()) t= t*10+aux[i]-'0';
    while(t--){
        vector<string> u(5);
        rep(i,5) getline(cin,u[i]);
        if(D.count(u)) cout<<"Solvable in "<<D[u]<<" move(s).\n";
        else cout<<"Unsolvable in less than 11 move(s).\n";
    }
    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);



    return 0;
}