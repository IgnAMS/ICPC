#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int w[n],h[n];
  int maxw=0;
  int xddd=0;

  for(int i=0;i<n;i++){
    cin>>w[i]>>h[i];
    if(h[i]>xddd) xddd=h[i];
    maxw+=w[i];
  }

  for(int i=0;i<n;i++){
    int maxh=0;
    int xd= maxw-w[i];

    for(int j=0;j<n;j++){
      if(h[j]>maxh && j!=i) maxh=h[j];
      if(maxh==xddd) break;
    }

    cout<<xd*maxh<<" ";
  }

  return 0;
}
