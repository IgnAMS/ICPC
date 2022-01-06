#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,q;
  cin>>n>>q;
  vector<int> nums(n);
  for(int i=0;i<n;i++) cin>>nums[i];
  vector<int> ans;
  for(int i=0;i<q;i++){
    int h;
    cin>>h;
    int low=0;
    int top=n;
    bool fond=false;
    int anss=-1;
    vector<int> visit(n,false);
    while(low<=top){
      int mid=(low+top)/2;
      if(visit[mid]) break;
      visit[mid]=true;
      //cout<<mid<<endl;
      if(nums[mid]==h){
        fond=true;
        //cout<<"encontrado en mid: "<<mid<<endl;
        while(mid+1<n  && nums[mid+1]==h){
          mid++;
        }
        anss=mid;
        break;
      }
      else if(nums[mid]<h){
        low=mid;
      }
      else if(nums[mid]>h){
        top=mid;
      }
    }
    ans.push_back(anss);
  }
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<endl;
  }


  return 0;
}
