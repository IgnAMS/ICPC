#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  while(n--){
    unsigned long long A,B;
    cin>>A>>B;
    int mult=0;
    if     (B>=999999999) mult=9;
    else if(B>=99999999 ) mult=8;
    else if(B>=9999999  ) mult=7;
    else if(B>=999999   ) mult=6;
    else if(B>=99999    ) mult=5;
    else if(B>=9999     ) mult=4;
    else if(B>=999      ) mult=3;
    else if(B>=99       ) mult=2;
    else if(B>=9        ) mult=1;
    else mult=0;

    unsigned long long asd=A*mult;
    cout<<A*mult<<endl;


  }



  return 0;
}
