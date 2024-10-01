#include <bits/stdc++.h>
using namespace std;
#define inf 100000000

int main() {
 int T;
 cin>>T;
 while(T--){
  int N,total;
  cin>>N>>total;
  int Array[N];
  int sum[total+1];
  sum[0]=0;

  for(int i=0;i<N;i++){
   cin>>Array[i];
  }

  for(int i=1;i<=total;i++){
   sum[i]=inf;
   for(int j=0;j<N;j++){
    if(i-Array[j]>=0 && sum[i-Array[j]]+1<sum[i]){
     sum[i]=min(sum[i],sum[i-Array[j]]+1);
     }
    //cout<<"el menor es = "<<sum<<endl;
   }
  }
  cout<<sum[total]<<endl;
}

  return 0;
}
