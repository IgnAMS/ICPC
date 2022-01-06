#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    string line;
    getline(cin, line); getline(cin, line);
    while(t--){ 
        vector<vector<vector<ii>>> P(101, vector<vector<ii>>(10));
        vector<bool> Aparece(101, 0);
        while(getline(cin, line) and line != ""){
            int contestant = 0, problem = 0, time = 0;
            int i = 0;
            while(line[i] != ' ') contestant = contestant * 10 + line[i] - '0', i++;
            i++;
            while(line[i] != ' ') problem = problem * 10 + line[i] - '0', i++;
            i++;
            while(line[i] != ' ') time = time * 10 + line[i] - '0', i++;
            i++;
            char L = line[i];
            Aparece[contestant] = 1;
            if(L != 'R' and L != 'U' and L != 'E')
                P[contestant][problem].push_back({time, L=='C'});
        }
        
        rep(i, 101) rep(j, 10){ 
            sort(P[i][j].begin(), P[i][j].end());
        }

        vector<vector<int>> Ans(101, {0, 0, 0}); // (Correctas, tiempo, numero) 
        rep(i, 101) Ans[i][2] = -i;
        rep(i, 101){
            rep(j, 10){
                int aux = 0;
                rep(x, P[i][j].size()){
                    if(P[i][j][x].ss == 1) {
                        Ans[i][1] -= aux + P[i][j][x].ff;
                        Ans[i][0]++;
                        break;
                    }
                    aux += 20;
                }
            }
        }
        cerr<<'\n';
        
        sort(Ans.begin(), Ans.end(), greater<vector<int>>());
        rep(i, 101){
            if(!Aparece[-Ans[i][2]]) continue;
            cout<<-Ans[i][2]<<' '<<Ans[i][0]<<' '<<-Ans[i][1]<<'\n';
        }
        if(t != 0) cout<<'\n';
    }


    return 0;
}