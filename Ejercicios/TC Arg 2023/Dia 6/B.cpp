#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define rep(i, n) for(int i = 0; i < n; i++)

string solve(int a, int b, int x)
{
    string s = "";
    int one = 0, cero = 0;
    rep(i, x)
    {
        if(i % 2 == 0){
            s += '1';
            one++;
        }
        else{
            s += '0';
            cero++;
        }
    }
    if(x % 2 == 1)
    {
        while(one < b){
            one++;
            s += '1';
        }
        while(cero < a)
        {
            s += '0';
            cero++;
        }
    }
    else{
        while(cero < a)
        {
            s += '0';
            cero++;
        }
        while(one < b){
            one++;
            s += '1';
        }
    }
    return s;
}

bool check(string s, int a, int b, int x)
{
    int na = 0, nb = 0, nx = 0;
    rep(i, s.size())
    {
        if(s[i] == '0')
            na++;
        else nb++;
        if(i > 0 and s[i-1] != s[i])
            nx++;
    }
    return (na == a and nb == b and x == nx);
}

int main() {
    int a, b, x;
    cin >> a >> b >> x;

    string s;
    s = solve(a, b, x);
    if(check(s, a, b, x))
    {
        cout << s << "\n";
        return 0;
    }
    //cout << s << endl;
    s = solve(b, a, x);

    rep(i, s.size())
    {
        if(s[i] == '1')
            s[i] = '0';
        else
            s[i] = '1';
    }
    //cout << s << endl;
    if(check(s, a, b, x))
    {
        cout << s << "\n";
        return 0;
    }

    return -1;
}   