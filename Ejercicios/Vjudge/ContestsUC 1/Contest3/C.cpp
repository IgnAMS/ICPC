#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int main(){
  int n;
  cin>>n;
  vector<ii> pos;
  vector<ii> neg;
  for(int i=0;i<n;i++){
    int xi,vi;
    cin>>xi>>vi;
    if(vi<0) neg.push_back(ii(xi,vi));
    else pos.push_back(ii(xi,vi));
  }
  double ans=INT_MAX;
  sort(neg.begin(),neg.end());
  sort(pos.begin(),pos.end());
  for(int i=0;i<neg.size();i++){
    for(int j=0;j<pos.size();j++){
      if(neg[i].first<pos[j].first) continue;
      double t=abs(neg[i].first-pos[j].first)*1.0/(pos[j].second-neg[i].second) ;
      ans=min(ans,t);
      //printf("la particula %d,%d choca con la particula %d,%d en el tiempo %lf\n",neg[i].first,neg[i].second,pos[j].first,pos[j].second,t);
    }
  }

  if(ans==INT_MAX) cout<<-1<<endl;
  else cout<<setprecision(11)<<fixed<<ans<<endl ;

  return 0;
}
