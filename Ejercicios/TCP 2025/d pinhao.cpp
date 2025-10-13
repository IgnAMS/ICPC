#include <bits/stdc++.h>
#ifdef jlocal
#include<jdebug/debug.hpp>
#else
#define debug(...) 0;
#endif
using namespace std;

#define endl "\n"
#define repf(i,k,n) for(int i=k; i<n; i++)
#define rep(i,n) for(int i=0; i<n; i++)

typedef vector<int> vi;
typedef long long ll;

int n;
vector<pair<pair<int,int>,string>> nums;
vector<pair<pair<int,int>,int>> or_x, or_y;
vector<int> visited;

const int maxn = 1e9;

int find_neighbour(int x, int dir){
	if(dir==1){
		int l = 0, r = n-1;
		while(l<=r){
			int mid = (l+r)/2;
			if(or_x[mid].first.first<nums[x].first.first ||(or_x[mid].first.first==nums[x].first.first && or_x[mid].first.second<nums[x].first.second)){
				l = mid+1;
			}else{
				r = mid-1;
			}
		}

		if(l>0 && or_x[l-1].first.first == nums[x].first.first)return or_x[l-1].second;
		return -1;
	}else if (dir == 2){
		int l = 0, r = n-1;
		while(l<=r){
			int mid = (l+r)/2;
			if(or_x[mid].first.first<nums[x].first.first ||(or_x[mid].first.first==nums[x].first.first && or_x[mid].first.second<nums[x].first.second)){
				l = mid+1;
			}else{
				r = mid-1;
			}
		}
		if(l<n-1 && or_x[l+1].first.first == nums[x].first.first)return or_x[l+1].second;
		return -1;
	}else if (dir==3){
		int l = 0, r = n-1;
		while(l<=r){
			int mid = (l+r)/2;
			if(or_y[mid].first.first<nums[x].first.second ||(or_y[mid].first.first==nums[x].first.second && or_y[mid].first.second<nums[x].first.first)){
				l = mid+1;
			}else{
				r = mid-1;
			}
		}
		if(l>0 && or_y[l-1].first.first == nums[x].first.second)return or_y[l-1].second;
		return -1;
	}else{
		int l = 0, r = n-1;
		while(l<=r){
			int mid = (l+r)/2;
			if(or_y[mid].first.first<nums[x].first.second ||(or_y[mid].first.first==nums[x].first.second && or_y[mid].first.second<nums[x].first.first)){
				l = mid+1;
			}else{
				r = mid-1;
			}
		}
		if(l<n-1 && or_y[l+1].first.first == nums[x].first.second)return or_y[l+1].second;
		return -1;
	}
}

void solve(){
	cin >> n;
	nums.resize(n),or_x.resize(n), or_y.resize(n);
	visited.assign(n,maxn);

	rep(i,n){
		int x,y;
		string dir;
		cin >> x >> y;
		cin >> dir;
		nums[i]= {{x,y},dir};
		or_x[i] = {{x,y},i};
		or_y[i] = {{y,x},i};
	}
	sort(or_x.begin(),or_x.end());
	sort(or_y.begin(),or_y.end());

	priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0,0});
	while(!pq.empty()){
		auto a = pq.top();
		debug(a);
		int i = a.second;
		pq.pop();
		if(visited[i]<=a.first)continue;
		visited[i]=a.first;
		int left = find_neighbour(i, 3);
		int right = find_neighbour(i, 4);
		int up = find_neighbour(i, 2);
		int down = find_neighbour(i, 1);
		debug(left);
		debug(right);
		debug(up);
		debug(down);
		if(left != -1 && visited[left]> visited[i] + (nums[i].second != "izquierda")) pq.push({visited[i] + (nums[i].second != "izquierda"), left});
		if(right != -1 && visited[right]> visited[i] + (nums[i].second != "derecha")) pq.push({visited[i] + (nums[i].second != "derecha"), right});
		if(up != -1 && visited[up]> visited[i] + (nums[i].second != "arriba")) pq.push({visited[i] + (nums[i].second != "arriba"), up});
		if(down != -1 && visited[down]> visited[i] + (nums[i].second != "abajo")) pq.push({visited[i] + (nums[i].second != "abajo"), down});
	}
	if(visited[n-1]==maxn)cout << -1 << endl;
	else cout << visited[n-1] << endl;
	debug(visited);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt = 1;
	//cin >> tt;
	while(tt--)solve();
	return 0;
}