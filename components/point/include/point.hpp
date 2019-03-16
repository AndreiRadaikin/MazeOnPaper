#pragma once

#include <utility>

namespace Point {
struct Point {
    Point();
    Point(const Point& p);
    Point(int x, int y);
    Point(std::pair<int, int> p);
    ~Point();
    int x_;
    int y_;

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
