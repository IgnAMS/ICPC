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
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> A(n); rep(i, n) cin>>A[i];
        bool pos1 = 1;
        int v1 = -1;
        int i = 0, j = n-1;
        while(i < j and pos1){
            if(A[i] != A[j] and v1 == -1){
                v1 = A[i];
                i++;
            }
            else if(A[i] != A[j] and A[j] == v1){
                j--;
            }
            else if(A[i] != A[j] and A[i] == v1){
                i++;
            }
            else if(A[i] != A[j]) pos1 = 0;
            else if(A[i] == A[j]) i++, j--;
        }
        bool pos2 = 1;
        v1 = -1;
        i = 0, j = n-1;
        while(i < j and pos2){
            if(A[i] != A[j] and v1 == -1){
                v1 = A[j];
                j--;
            }
            else if(A[i] != A[j] and A[j] == v1){
                j--;
            }
            else if(A[i] != A[j] and A[i] == v1){
                i++;
            }
            else if(A[i] != A[j]) pos2 = 0;
            else if(A[i] == A[j]) i++, j--;
        }
        // cout<<(pos1 or pos2)<<'\n';
        if(pos1 or pos2) cout<<"YES\n";
        else cout<<"NO\n";
    }



    return 0;
}