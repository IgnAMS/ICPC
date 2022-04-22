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
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

#define M_PI 3.14159265358979323846

double b, c;
double f(double x) { 
    return (x * x + b * x + c) / sin(x);
}
// find minimum (convex function)
double min_ternary_search(double l, double r, int times) {
    while (times--) {
        double d = (r - l) / 3.0;
        double m1 = l + d, m2 = r - d;
        double f1 = f(m1), f2 = f(m2);
        if (f1 <= f2) r = m2;
        if (f1 >= f2) l = m1;
    }
    return f((l+r)*.5);
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        cin>>b>>c;
        cout<<setprecision(8)<<fixed<<min_ternary_search(0, M_PI, 100)<<'\n';
    }


    return 0;
}