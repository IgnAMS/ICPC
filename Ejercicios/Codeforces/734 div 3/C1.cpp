#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t; 
    while(t--){
        int n; cin>>n;
        int A[n][5]; memset(A, 0, sizeof A);
        vector<vector<int>> B(5, vector<int>(n, 0)); 
        string s;
        string abc = "abcde";
        rep(i,n) {
            cin>>s;
            for(auto& c:s) A[i][c - 'a']++;
            for(auto& c: abc) {
                B[c - 'a'][i] = A[i][c - 'a'];
                for(auto& c2: abc) if(c != c2){
                    B[c - 'a'][i] -= A[i][c2 - 'a'];
                }
            }
        }    
        // maxima suma no negativa
        rep(i, 5) sort(B[i].begin(), B[i].end(), greater<int>()); 
        int maxi = 0;
        rep(i, 5){
            int suma = 0;
            rep(j, n) {
                //cout<<B[i][j]<<' ';
                suma += B[i][j];
                if(suma >= 1) maxi = max(maxi, j + 1);
                else break;
            }
            // cout<<'\n'<<i<<' '<<maxi<<'\n';
        }
        cout<<maxi<<'\n';
    }





    return 0;
}