#include "template.cpp"

const db PI = acos(-1.0L);
const db EPS = 1e-12;

typedef db T; struct P {
    T x, y, z;
    P(): x(0), y(0), z(0) {}
    P(db x, db y, db z) : x(x), y(y), z(z) {}

    P operator+(const P &p) const { return P(x + p.x, y + p.y, z + p.z); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y, z - p.z); }
    P operator*(const db &c) const { return P(x * c, y * c, z * c); }
    P operator/(const db &c) const { return P(x / c, y / c, z / c); }
    P operator^(const P &p) const {
        return P(y * p.z - z * p.y, 
                 z * p.x - x * p.z,
                 x * p.y - y * p.x);
    }
    T operator*(const P &p) const { return x * p.x + y * p.y + z * p.z; }
};

// returns A, B, C, k such that Ax + By + Cz + k = 0 for the plane
pair<P, T> plane(P& a, P& b, P& c) {
    P normal = (b - a) ^ (c - a);
    pair<P, db> p = {normal, (a * normal) * -1};
    return p;
};