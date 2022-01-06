#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define ff first
#define ss second
#define mp make_pair


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll L,C,N;
    while(cin>>L>>C>>N){
        vector<int> F(C+3,0);
        set<pair<ii,int>> s;
        F[1]=L;
        s.insert(mp(ii(0,L-1),1));
        ll P,X,A,B;
        while(N--){
            cin>>P>>X>>A>>B;
            ll S=F[P];
            int m1= (A+S*S)%L;
            int m2= (A+ (B+S)*(B+S))%L;
            if(m2<m1) swap(m1,m2);
            F[X]+= m2-m1+1;
            pair<ii,int> i= mp(ii(m1,m2),X);
            //cerr<<m1<<" "<<m2<<endl;
            auto it1= s.lower_bound(i);
            
            if(it1!=s.begin() && prev(it1)->ff.ss >= m1) --it1;
            
            auto it2=it1;
            while(it2!=s.end() && (*it2).ff.ff <= m2) ++it2;
            
            for(auto it=it1; it!=(it2); ++it){
                int a= max(m1,it->ff.ff);
                int b= min(m2,it->ff.ss);
                //cout<<a<<" "<<b<<endl;
                F[it->ss]-= (b-a+1);
                //cerr<<F[it->ss]<<endl;
            }
            
            auto a= *it1;
            auto b= *it2;
            s.erase(it1,it2);
            s.insert(i);
            if(a.ff.ff < m1) s.insert(mp(ii(a.ff.ff,m1-1),a.ss));
            if(b.ff.ss > m2) s.insert(mp(ii(m2+1,b.ff.ss),b.ss));
            //break;
        }
        cout<<(*max_element(F.begin(),F.end()))<<endl;
    }


    return 0;
}