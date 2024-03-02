#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
using li = long long;
using ld = long double;
void solve(bool);
void precalc();
clock_t start;
int main() {
#ifdef AIM
  freopen("/home/alexandero/CLionProjects/ACM/input.txt", "r", stdin);
//freopen("/home/alexandero/CLionProjects/ACM/output.txt", "w", stdout);
//freopen("out.txt", "w", stdout);
#else
  //freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#endif
  start = clock();
  int t = 1;
#ifndef AIM
  cout.sync_with_stdio(0);
  cin.tie(0);
#endif
  cout.precision(20);
  cout << fixed;
//cin >> t;
  precalc();
  while (t--) {
    solve(true);
  }
  cout.flush();

#ifdef AIM1
  while (true) {
solve(false);
}
#endif

#ifdef AIM
  cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif
  return 0;
}

//BE CAREFUL: IS INT REALLY INT?

template<typename T>
T binpow(T q, T w, T mod) {
  if (!w)
    return 1 % mod;
  if (w & 1)
    return q * 1LL * binpow(q, w - 1, mod) % mod;
  return binpow(q * 1LL * q % mod, w / 2, mod);
}

template<typename T>
T gcd(T q, T w) {
  while (w) {
    q %= w;
    swap(q, w);
  }
  return q;
}
template<typename T>
T lcm(T q, T w) {
  return q / gcd(q, w) * w;
}

template <typename T>
void make_unique(vector<T>& vec) {
  sort(all(vec));
  vec.erase(unique(all(vec)), vec.end());
}

template<typename T>
void relax_min(T& cur, T val) {
  cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
  cur = max(cur, val);
}

void precalc() {

}

#define int li
//const li mod = 1000000007;
//using ull = unsigned long long;

struct Point {
  int x, y;
  Point() {}
  Point(int x, int y) : x(x), y(y) {}
  Point operator - (const Point& ot) const {
    return Point(x - ot.x, y - ot.y);
  }
  int operator * (const Point& ot) const {
    return x * ot.y - y * ot.x;
  }
  void scan() {
    cin >> x >> y;
  }
  bool operator < (const Point& ot) const {
    return make_pair(x, y) < make_pair(ot.x, ot.y);
  }
  int sqr_len() const {
    return x * x + y * y;
  }
  long double get_len() const {
    return sqrtl(sqr_len());
  }
  int operator % (const Point& ot) const {
    return x * ot.x + y * ot.y;
  }
};

struct Polygon {
  vector<Point> hull;
  Polygon(int n) {
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
      points[i].scan();
    }
    sort(all(points));
    vector<Point> up, down;
    for (auto& pt : points) {
      while (up.size() > 1 && (up[up.size() - 2] - up.back()) * (pt - up.back()) >= 0) {
        up.pop_back();
      }
      up.push_back(pt);
      while (down.size() > 1 && (down[down.size() - 2] - down.back()) * (pt - down.back()) <= 0) {
        down.pop_back();
      }
      down.push_back(pt);
    }
    hull = up;
    for (int i = (int)down.size() - 2; i > 0; --i) {
      hull.push_back(down[i]);
    }
  }
  int sqr_len(int pos) const {
    return (hull[(pos + 1) % hull.size()] - hull[pos]).sqr_len();
  }
  int size() const {
    return (int)hull.size();
  }
  long double get_angle(int pos) const {
    auto a = hull[(pos + 1) % hull.size()] - hull[pos], b = hull[(pos + hull.size() - 1) % hull.size()] - hull[pos];
    long double co = (a % b) / a.get_len() / b.get_len();
    return co;
  }
};

void solve(bool read) {
  vector<Polygon> polys;
  int n[2];
  cin >> n[0] >> n[1];
  for (int i = 0; i < 2; ++i) {
    polys.emplace_back(n[i]);
  }
  if (polys[0].size() != polys[1].size()) {
    cout << "NO\n";
    return;
  }
  vector<long double> all_lens;
  int m = polys[0].size();
  for (int i = 0; i < m; ++i) {
    all_lens.push_back(polys[0].sqr_len(i));
    all_lens.push_back(polys[0].get_angle(i));
  }
  all_lens.push_back(-1);
  for (int j = 0; j < 2; ++j) {
    for (int i = 0; i < m; ++i) {
      all_lens.push_back(polys[1].sqr_len(i));
      all_lens.push_back(polys[1].get_angle(i));
    }
  }
  /*for (int x : all_lens) {
    cout << x << " ";
  }
  cout << "\n";*/
  vector<int> p(all_lens.size());
  for (int i = 1; i < p.size(); ++i) {
    int j = p[i - 1];
    while (j > 0 && all_lens[i] != all_lens[j]) {
      j = p[j - 1];
    }
    if (all_lens[i] == all_lens[j]) {
      ++j;
    }
    p[i] = j;
    if (p[i] == 2 * m) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";

}