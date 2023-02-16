#include "../template.cpp"

// Casini:      F_{n-1} * F_{n+1} - F_n ^ 2 = (-1)^n
// Addition:    F_{n + k} = F_{k} * F_{n + 1} + F_{k - 1} * F_{n}
// Addition2:   F_{2n} = F_n * (F_{n+1} + F_{n-1})
// Addition3:   F_n divide F_m ssi n divide a m
// GCD:         gcd(F_n, F_m) = F_{gcd(n,m)}
// Formula:     F_n = (((1+sqrt(5))/2)^n - ((1-sqrt(5))/2)^n) / sqrt(5)
// Approx:      F_n ~ [((1+sqrt(5))/2)^n/sqrt(5)]
// Matrix:      P = {{0, 1}, {1, 1}}

// Fast doubling method
pll fib(n) {
    if(n == 0) return {0, 1};
    auto p = fib(n>>1);
    int c = p.first * (2 * p.second - p.fisrt);
    int d = p.first * p.first + p.second * p.second;
    if(n & 1) return {d, c + d};
    else return {c, d};
}

