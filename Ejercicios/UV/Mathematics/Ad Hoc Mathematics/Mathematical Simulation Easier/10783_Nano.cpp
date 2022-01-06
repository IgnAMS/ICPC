#include<bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin>>T;
  int t=0;
  while(T--){
    t++;
    int a,b;
    cin>>a>>b;
    if(a%2==0) a++;
    int sum=0;
    for(int i=a;i<=b;i+=2){
      sum+=i;
    }
    printf("Case %d: %d\n",t,sum);
  }

  return 0;
}
