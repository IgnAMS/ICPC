#include "../template.cpp"

const ll mod = 1e9 + 7;

inline ll add(ll x, ll y, ll M = MOD) { return (x + y + 2 * M) % M; }
inline ll mul(ll x, ll y, ll M = MOD) { return (x * y) % M; }


// Note: b >> m and m prime then x ^ n = x ^ {n % (m - 1)}
ll binPow(ll a, ll b, const ll M) {
    ll res = 1;
    while(b > 0) {
        if(b & 1) res = mul(res, a, M);
        a = mul(a, a, M);
        b >>= 1;
    }
    return res;
}

// MODULAR INVERSE: x tq a * x % m = 1, exists ssi gcd(a, m) = 1
// Using diohpantine: a * x + m * y = 1
// find x in [0, M) such that Ax = 1 mod M
#include "Euclid.cpp"
ll minv(ll A, ll M) {
    pll p = euclid(A, M);
    assert(p.ff * A + p.ss * M == 1);
    return p.ff + (p.ff < 0) * M;
}

// Binary exponentiation: a and b relative primes -> a ^ phi(m) % m = 1 -> a ^ {phi(m) - 1} % mod = a^-1
// Binary exponentiation: m prime -> a ^ {m - 1} % m = 1 -> a ^ {m - 2} % mod = 1

// Euclidean division, O(log(m) / log(log(m))) less than 50 iterations with 10^9
int inv(int i) {
  return i <= 1 ? i : m - (ll)(m / i) * inv(m % i) % m;
}

// Modular inverse of an array
// x_{i} ^ -1 = prefix_{i-1} * suffix{i+1} * (x1 * x2 * ... * x_n) ^ -1
#include "Euclid.cpp"
vl invs(vl &a, int m) {
    int n = a.size();
    if (n == 0) return {};
    vl b(n);
    ll v = 1;
    for (int i = 0; i != n; ++i) {
        b[i] = v;
        v = (v * a[i]) % m;
    }
    pll p = euclid(v, m); 
    ll x = p.ff, y = p.ss;
    x = (x % m + m) % m;
    for (int i = n - 1; i >= 0; --i) {
        b[i] = (x * b[i]) % m;
        x = (x * a[i]) % m;
    }
    return b;
}

// LINEAR CONGUENCE EQUATION
// find x such that a * x % m = b
ll linear_congruence(ll a, ll b, ll m) {
    a %= m, b %= m;
    int g = gcd(a, n);
    if(g % b) return -1;
    return (minv(a, m) * b) % m;
    // more solutions: x_i = (x + i * m) % m for all i in [0, g - 1]
}

// CRT for coprime modules
// Use garner for non coprimes modules
struct Congruence { ll a, m; };

ll chinese_remainder_theorem(vector<Congruence> const& congruences) {
    ll M = 1, solution = 0;
    for (auto const& congruence : congruences) M *= congruence.m;
    for (auto const& congruence : congruences) {
        ll a_i = congruence.a;
        ll M_i = M / congruence.m;
        ll N_i = mod_inv(M_i, congruence.m);
        solution = (solution + a_i * M_i % M * N_i) % M;
    }
    return solution;
}


// DISCRETE LOGARITHM
// Returns minimum x for which a ^ x % m = b % m in O(sqrt(m))
// Includes case when a and m are not coprime dividing by the gcd
int solve(int a, int b, int m) {
    a %= m, b %= m;
    int k = 1, add = 0, g;
    while ((g = __gcd(a, m)) > 1) {
        if (b == k)
            return add;
        if (b % g)
            return -1;
        b /= g, m /= g, ++add;
        k = (k * 1ll * a / g) % m;
    }

    int n = sqrt(m) + 1;
    int an = 1;
    rep(i, n) an = (an * 1ll * a) % m;

    unordered_map<int, int> vals;
    for (int q = 0, cur = b; q <= n; ++q) {
        vals[cur] = q;
        cur = (cur * 1ll * a) % m;
    }

    for (int p = 1, cur = k; p <= n; ++p) {
        cur = (cur * 1ll * an) % m;
        if (vals.count(cur)) {
            int ans = n * p - vals[cur] + add;
            return ans;
        }
    }
    return -1;
}


// DISCRETE ROOT AND PRIMITIVE ROOT
// Finds the primitive root modulo p
ll generator(int p) {
    vl fact;
    int phi = p-1, n = phi;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            fact.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) fact.push_back(n);

    for (int res = 2; res <= p; ++res) {
        bool ok = true;
        for (auto factor : fact) {
            if (binPow(res, phi / factor, p) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return res;
    }
    return -1;
}

// This program finds all numbers x such that x^k = a (mod n)
vl solve(ll k, ll a, ll n) {
    if(a == 0) return {0, 1};

    int g = generator(n);

    // Baby-step giant-step discrete logarithm algorithm
    int sq = sqrt(n) + 1;
    vector<pll> dec(sq);
    repx(i, 1, sq + 1)
        dec[i-1] = {binPow(g, i * sq * k % (n - 1), n), i};
    sort(dec.begin(), dec.end());
    int any_ans = -1;
    rep(i, sq) {
        int my = binPow(g, i * k % (n - 1), n) * a % n;
        auto it = lower_bound(dec.begin(), dec.end(), {my, 0});
        if (it != dec.end() && it->first == my) {
            any_ans = it->second * sq - i;
            break;
        }
    }
    if (any_ans == -1) {
        return {0};
    }

    // Print all possible answers
    int delta = (n-1) / __gcd(k, n-1);
    vl ans;
    for (int cur = any_ans % delta; cur < n-1; cur += delta)
        ans.push_back(binPow(g, cur, n));
    sort(ans.begin(), ans.end());
    return ans;
}



// Goes over ll
ul modMul(ul a, ul b, const ul M) {
    ll r = a * b - M (uk)((db)a * b / M);
    return r + ((r < 0) - (r >= (ll)M)) * M;
}

ul modPow(ul a, ul b, const ul M) {
    if(b == 0) return 1;
    ul r = modPow(a, b / 2, M); r = modMul(r, r, M);
    return (b & 1) ? modMul(r, a, M): r;
}