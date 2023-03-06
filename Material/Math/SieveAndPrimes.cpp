#include "../template.cpp"

// O(n log(log(sqrt(n))))]
// Number of primes ~ n / log(n)
// big constant by repeating isP[j] = 0 assignations
// Options: bitset, vector<char>, vector<bool> 
vl sieve(int n = 320000) {
    vector<bool> isP(n + 1, 1);
    for(int i = 2; i * i <= n; i++) {
        if(isP[i] and (ll) i * i <= n) {
            for(ll j = i * i; j <= n; j += i) isP[j] = 0;
        }
    }
    vl P;
    repx(i, 2, n + 1) if(isP[i]) P.pb(i);
    return P;
}

// Primes in range [L, R] in O((R - L + 1) Log(Log(R)) + sqrt(R) * Log(Log(sqrt(R))))
// R ~ 1e12
vector<bool> segmentedSieve(ll L, ll R) {
    // generate all primes up to sqrt(R)
    ll lim = sqrt(R);
    vector<bool> mark(lim + 1, false);
    vl primes;
    repx(i, 2, lim + 1) {
        if (!mark[i]) {
            primes.pb(i);
            for (ll j = i * i; j <= lim; j += i)
                mark[j] = 1;
        }
    }

    vector<bool> isPrime(R - L + 1, true);
    for (ll i : primes)
        for (ll j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

// Linear Sieve: O(n)
// Uses more memory
vl linearSieve(int n = 10000000) {
    vl lp(n + 1, 0);
    vl pr;
    repx(i, 2, n + 1) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.pb(i);
        }
        for (int j = 0; i * pr[j] <= n; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }
}

// PRIMALITY TEST
// Trial Division O(sqrt(n))
bool isPrime(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return true;
}

// Fermat theorem: a ^ (p - 1) % p = 1 for all a
// 646 of 10^9 fails
// O(1)
bool probablyPrimeFermat(int n, int iter=5) {
    if (n < 4)
        return n == 2 || n == 3;

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (binpower(a, n - 1, n) != 1)
            return false;
    }
    return true;
}

// Miller Rabin
// Probabilistic check for prime numbers
// 88% of the numbers have a prime factor under 100, optimize the checker checking these cases
using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1) result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1) return false;
    }
    return true;
};

bool MillerRabin(u64 n, int iter=5) { // returns true if n is probably prime, else returns false.
    if (n < 4) return n == 2 || n == 3;
    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }
    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}

// Deterministic MillerRabin
bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
    if (n < 2) return false;
    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a) return true;
        if (check_composite(n, a, d, r)) return false;
    }
    return true;
}

