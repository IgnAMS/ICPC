    #pragma GCC optimize("Ofast")
    #include<bits/stdc++.h>
    using namespace std;
    #define repx(i,a,b) for(int i=a; i<b; i++)
    #define rep(i,n) repx(i,0,n)
    typedef long long ll;
    typedef pair<ll, ll> pll;
    typedef double db;
    typedef vector<ll> vl;
    #define ff first
    #define ss second
    #define pb push_back
    // g++ -std=c++17 E.cpp -o a && a <input.txt> output.txt
    // ulimit -s 1000000
    // g++ -O2 .cpp && time ./a.out <input.txt> output.txt

    int main(){
        ios::sync_with_stdio(0); cin.tie(0);
        int t; cin>>t;
        while(t--) {
            int n; cin>>n;
            vl A(n + 1, 1);
            ll prev = 1, acc = 0, zeros = 0, last = 1;
            repx(i, 2, n + 1) {
                cout<<"? "<<1<<' '<<i<<endl;
                ll x; cin>>x;
                if(x - acc) {
                    ll y = x - acc - zeros;
                    zeros += y;
                    for(int j = i - 1; j >= i - y; j--) {
                        A[j] = 0;
                    }
                    A[i] = 1;
                    acc = x;
                    last = i;
                }
                else if(zeros) A[i] = 0;
                else A[i] = 1;
            }


            if(last == 1) cout<<"! IMPOSSIBLE"<<endl;
            else {
                cout<<"! ";
                repx(i, 1, n + 1) cout<<A[i]; cout<<endl;
            }


        }

        return 0;
    }