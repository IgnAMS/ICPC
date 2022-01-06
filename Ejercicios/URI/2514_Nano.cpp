#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

int main() {
  int n,a,b,c;
  while(cin>>n>>a>>b>>c){
    int uno = lcm(a,b);
    int dos= lcm(uno,c);
    int answer= dos-n;
    //cout<<dos<<endl;
    cout<<answer<<endl;
  }
	return 0;
}
