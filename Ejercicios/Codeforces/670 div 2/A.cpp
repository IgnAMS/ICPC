#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;



int main() {
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    vector<bool> a(102,false),b(102,false);
    int arr[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
      if(!a[arr[i]]) a[arr[i]]=true;
      else b[arr[i]]=true;
    }
    int ans=0;
    int i=0, j=0;
    while(a[i]) i++;
    while(b[j]) j++;


    cout<<i+j<<"\n";
  }


	return 0;
}
