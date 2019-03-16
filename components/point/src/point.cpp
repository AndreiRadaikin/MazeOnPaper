#include "point.hpp"

namespace Point {

Point::Point():x_(0), y_(0) {}

Point::Point(const Point &p):x_(p.x_), y_(p.y_){}

Point::Point(int x, int y): x_(x), y_(y) {}

Point::Point(std::pair<int, int> p):x_(p.first), y_(p.second){}

Point::~Point() {}

Point &Point::operator =(const Point &p) {
    if(this == &p) return *this;
    x_ = p.x_;
    y_ = p.y_;
    return *this;
}

Point &Point::operator -=(const Point &p) {
    x_-=p.x_;
    y_-=p.y_;
    return *this;
}

Point &Point::operator +=(const Point &p) {
    x_+=p.x_;
    y_+=p.y_;
    return *this;
}

bool Point::operator ==(const Point &p) const {
    return x_ == p.x_ && y_ == p.y_;
}

bool Point::operator > (const Point &p) const {
    if(x_ == p.x_) return y_ > p.y_;
    return x_ > p.x_;
}

bool Point::operator >=(const Point &p) const {
    return *this > p || *this == p;
}

bool Point::operator < (const Point &p) const {
    if(x_ == p.x_) return y_ < p.y_;
    return x_ < p.x_;
}

bool Point::operator <= (const Point &p) const {
    return *this < p || *this == p;
}

Point operator+(const Point &lp, const Point &rp) {
    return Point(lp.x_ + rp.x_, lp.y_ + rp.y_);
}

Point operator-(const Point &lp, const Point &rp) {
    return Point(lp.x_ - rp.x_, lp.y_ - rp.y_);
}
}
