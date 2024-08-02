#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define repx(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define rep(i, n) repx(i, 0, n)
#define ff first
#define ss second
typedef pair<ll, ll> pll;

const double PI = acos(-1.0L);


int main() {
    int l, r;
    cin >> l >> r;
    vector<int> f1, f2;
    for(int i = l; i<=r; ++i){
        string s;
        cin >> s;
        if(s == "Fizz" || s == "FizzBuzz"){
            f1.push_back(i);
        }
        if(s == "Buzz" || s == "FizzBuzz"){
            f2.push_back(i);
        }
    }
    int a = -1, b = -1;
    if(f1.size() == 0){
        a = (int)2e5;
    }else if(f1.size() == 1){
        a = f1[0];
    }else{
        a = f1[1]-f1[0];
    }

    if(f2.size() == 0){
        b = (int)2e5;
    }else if(f2.size() == 1){
        b = f2[0]; 
    }else{
        b = f2[1]-f2[0];
    }
    cout << a << " " << b << "\n";




    return 0;
}