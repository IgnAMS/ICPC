#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<int> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vi A(3); 
    while(cin>>A[0]>>A[1]>>A[2] and A[0]){
        sort(A.begin(), A.end());
        if(A[0] == A[2]){
            if(A[0] == 13) cout<<"*\n";
            else cout<<A[0] + 1<<' '<<A[0] + 1<<' '<<A[0] + 1<<'\n';
        }
        else if(A[0] == A[1]) {
            if(A[2] != 13) cout<<A[0]<<' '<<A[1]<<' '<<A[2] + 1<<'\n';
            else cout<<1<<' '<<A[0] + 1<<' '<<A[1] + 1<<'\n';
        }
        else if(A[1] == A[2]){
            if(A[0] + 1 != A[1]) cout<<A[0] + 1<<' '<<A[1]<<' '<<A[2]<<'\n';
            else{
                if(A[1] == 13) cout<<"1 1 1\n";
                else cout<<A[1]<<' '<<A[1]<<' '<<A[1] + 1<<'\n';
            }
        }
        else cout<<"1 1 2\n";
        
    }





    return 0;
}