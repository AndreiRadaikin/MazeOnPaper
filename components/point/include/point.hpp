#pragma once

#include <utility>

namespace Point {
struct Point {
    Point();
    Point(const Point& p);
    Point(long long x, long long y);
    Point(std::pair<long long, long long> p);
    ~Point();
    long long x_;
    long long y_;

    Point &operator = (const Point &p);
    Point &operator -= (const Point &p);
    Point &operator += (const Point &lp);

    bool operator == (const Point &p) const;
    bool operator > (const Point &p) const;
    bool operator >= (const Point &p) const;
    bool operator < (const Point &p) const;
    bool operator <= (const Point &p) const;
};

Point operator + (const Point &lp, const Point &rp);
Point operator - (const Point &lp, const Point &rp);
}
