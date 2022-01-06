#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second


ll INF = 1e17;

ll DP[8005][8005];

int n;

int main(){
    cin>>n;
    vector<ll> A(n); rep(i, n) cin>>A[i];
    ll maxi = 0; 
    rep(i, 8005) rep(j, 8005) DP[i][j] = INF;

    for(int i = n-1; i>= 0; i--) maxi = max(A[i], maxi), DP[1][i] = maxi;
    for(int k = 2; k<=n; k++){
        vector<ll> mins; // min stack
        vector<ll> st; // stack
        vector<int> ind;
        ll minc = DP[k-1][n-k+1]; // minc de la region
        ll curr = 1e5;
        for(int i = n - k; i >= 0; i--){
            if(!st.empty() and A[i] >= st.back()) { // se fusiona la region, mantiene el minc
                minc = DP[k-1][i+1];
                int aux = 0;
                while(!st.empty() and st.back() <= A[i]){ // busco la ultima respuesta util 
                    minc = min(mins.back(), minc);
                    st.pop_back(); mins.pop_back(); ind.pop_back();
                    aux++;
                }
                DP[k][i] = A[i] + minc;
                if(!st.empty()) // si puedo actualizar, obtengo la mejor sol
                    DP[k][i] = min(DP[k][i], DP[k][ind.back()]);   
                st.push_back(A[i]);
                mins.push_back(minc);
                ind.push_back(i);
            }
            else{ // se crea una nueva region, se debe resetear el minc
                DP[k][i] = min(DP[k][i+1], A[i] + DP[k-1][i+1]);
                st.push_back(A[i]);
                mins.push_back(DP[k-1][i+1]);
                ind.push_back(i);
            }
        }
    }
    // rep(i, n+1) { rep(j, n+1) cout<<DP[i][j]<<' '; cout<<'\n'; }
    multiset<int> S;
    rep(i, n) S.insert(A[i]);
    maxi = 0;
    repx(k, 1, n+1){
        maxi += *S.rbegin(); S.erase(S.find(*S.rbegin()));
        cout<<DP[k][0]<<' '<<maxi<<'\n';
    }


    return 0;
}