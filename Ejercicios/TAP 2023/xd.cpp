#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
#define double long double
#define all(v) v.begin(),v.end()

void dbg_out() {cerr <<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){ cerr << ' ' << h; dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

namespace geo {
	constexpr double EPS = 1e-10;
	bool zero(double x) {
		return abs(x) < EPS;
	}

	struct point {
		double x, y;
		point(double _x=0, double _y=0): x(_x), y(_y) {}

		point operator+(point rhs) { return point(x+rhs.x, y+rhs.y); }
		point operator-(point rhs) { return point(x-rhs.x, y-rhs.y); }
		double operator^(point rhs) { return x*rhs.y - y*rhs.x; }
		double operator*(point rhs) { return x*rhs.x + y*rhs.y; }
		point operator*(double k) { return point(k*x, k*y); }

		bool operator<(const point& rhs) const {
			return x < rhs.x - EPS || (zero(x-rhs.x) && y < rhs.y - EPS);
		}
		bool operator==(const point& rhs) const {
			return zero(x-rhs.x) && zero(y - rhs.y);
		}
		double norm2() {
			return *this * *this;
		}
	};

	template <bool CCW>
	bool ang_cmp(point a, point b) {
		if(zero(a^b)) {
			return a.norm2() < b.norm2();
		}
		if(CCW) return (a^b) > 0;
		else return (a^b) < 0;
	}

	double dist2(point a, point b) {
		return (b-a) * (b-a);
	}

	double area2(point a, point b, point c) {
		return (b-a)^(c-a);
	}

	bool left(point a, point b, point c) {
		return area2(a,b,c) > EPS;
	}

	bool collinear(point a, point b, point c) {
		return zero(area2(a,b,c));
	}

	struct segment {
		point a, b;
		segment(point _a = point(), point _b = point()): a(_a), b(_b) {}

		point v() { return b - a; }
	};

	point proj(segment r, point p) {
		p = p - r.a;
		point v = r.v();
		return r.a + v * ( (p*v) / (v*v) );
	}
}

//double key(segment r, point p) {
//	return dist2(p, proj(r, p));
//}
//
//int solve(const segment& t, const vector<point>& pts, bool left) {
//	int good = 0;
//	for(int i=0;i<2;i++) {
//		point o = i == 0 ? t.a : t.b;
//		auto v = pts;
//		for(auto &p: v) p = p - o;
//
//		if(left ^ bool(i)) {
//			sort(all(v), ang_cmp<true>);
//		} else {
//			sort(all(v), ang_cmp<false>);
//		}
//
//		for(auto &p: v) p = p + o;
//
//		dbg(i, left);
//		for(auto p: v) dbg(p.x, p.y);
//
//		ordered_set<pair<double, point>> set;
//
//		for(auto p: v) {
//			good += set.size() - 
//				set.order_of_key({key(t, p) + (i==0 ? -EPS : EPS), point()});
//			dbg(key(t, p));
//
//			set.insert({key(t, p), p});
//		}
//	}
//	dbg(good);
//	return pts.size() * (pts.size() - 1) / 2 -  good;
//}
//
//void solve() {
//	int xs, ys, xe, ye;
//	cin >> xs >> ys >> xe >> ye;
//	segment t( point(xs, ys), point(xe, ye) );
//	
//	int cnt[4]; memset( cnt, 0, sizeof(cnt) );
//
//	vector<point> l, r;
//
//	int n; cin >> n;
//
//	for(int i=0;i<n;i++) {
//		int x, y;
//		cin >> x >> y;
//		point p(x, y);
//		if(collinear(t.a, t.b, p)) {
//			if(t.v() * (p - t.a) > 0) cnt[0]++;
//			else cnt[1]++;
//		} else {
//			if(left(t.a, t.b, p)) {
//				l.push_back(p);
//			} else {
//				r.push_back(p);
//			}
//		}
//	}
//
//	dbg(l.size());
//	for(auto p: l) dbg(p.x, p.y);
//	dbg(r.size());
//	for(auto p: r) dbg(p.x, p.y);
//
//	cnt[2] = solve(t, l, true);
//	cnt[3] = solve(t, r, false);
//
//	int ans = cnt[0] * (cnt[0] - 1) / 2;
//	ans += cnt[1] * (cnt[1] - 1) / 2;
//
//	ans += cnt[2];
//	ans += cnt[3];
//
//	dbg(cnt[0], cnt[1], cnt[2], cnt[3])
//
//	cout << ans << endl;
//}

using namespace geo;

int solve(const segment& t, const vector<point> &pts, bool left) {
	int good = 0;

	vector<point> v = pts;
	for(auto& p: v) p = p - t.a;
	if(left) {
		sort(all(v), ang_cmp<true>);
	} else {
		sort(all(v), ang_cmp<false>);
	}
	for(auto& p: v) p = p + t.a;
	ordered_set<pair<double, point>> ord;
	for(point p: v) {	
		double d = dist2(p, proj(t, p));
		good += ord.size() - 
			ord.order_of_key({d - EPS, point()});
		dbg(d);
		ord.insert({d, p});
	}

}

void solve() {
	int xs, ys, xe, ye; cin >> xs >> ys >> xe >> ye;
	segment t( point(xs, ys), point(xe, ye));
	int n; cin >> n;

	int col[2] = {0, 0};

	vector<point> l, r;

	for(int i=0;i<n;i++) {
		int x, y; cin >> x >> y;
		point p(x, y);
		if(collinear(t.a, t.b, p)) {
			if( (t.b - t.a) * (p - t.a) > 0 ) col[0]++;
			else col[1]++;
		} else if(left(t.a, t.b, p)) {
			l.push_back(p);
		} else {
			r.push_back(p);
		}
	}

	int ans = 0;
	for(int i=0;i<2;i++) ans += col[i] * (col[i]-1) / 2;

	ans += solve(t, l, true);
	ans += solve(t, r, false);

	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}