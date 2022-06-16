#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; 
    while(cin>>n and n) {
        // cout<<"n: "<<n<<'\n';
        vector<ii> A(n);
        rep(i, n) {
            A[i].ss = i;
            cin>>A[i].ff; A[i].ff--;
        }
        int cont = 0;
        vi V(n, 0);
        rep(i, n) {
            if(!V[A[i].ff]) cont++; 
            V[A[i].ff] = 1;
        }
        if(cont != n) {
            cout<<"No solution\n";
            continue;
        }

        vi Pos(n), B(n);
        rep(i, n) Pos[i] = i, B[i] = i;
        rep(i, n) 
        sort(A.begin(), A.end());

        vi Ans;
        rep(i, n) { 
            for(int j = Pos[A[i].ss]; j > i; j--) {
                Ans.push_back(j);
                swap(Pos[B[j]], Pos[B[j - 1]]);
                swap(B[j], B[j - 1]);
            }
        }

        cout<<Ans.size()<<" \n"[Ans.size() == 0];
        rep(i, Ans.size()) cout<<Ans[i]<<" \n"[i == Ans.size() - 1];


        


    }


    return 0;
}