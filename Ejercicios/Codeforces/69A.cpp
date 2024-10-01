#include <iostream>
using namespace std;

int main() {
  int n;
  cin>>n;
  int sumX=0, sumY=0, sumZ=0;
  while(n--){
    int a,b,c;
    cin>>a>>b>>c;
    sumX+=a;
    sumY+=b;
    sumZ+=c;
  }
  if(sumX==0 && sumY==0 && sumZ==0) cout<<"YES\n";
  else cout<<"NO\n";
	return 0;
}
