#pragma once
#include <iostream>
#include <vector>
#include "point.hpp"
#include "direction.hpp"
#include "field_type.hpp"

namespace Maze {

class Maze {
public:
    Maze();
    bool CanMoveFromTo(Point::Point from, Point::Point to) const;
    bool CanMoveFromTo(Point::Point from, Direction::Direction to) const;
    FieldType::Type GetType(Point::Point point) const;
private:
    size_t V(const Point::Point &point) const;
    void SetWall(size_t from, size_t to);
//    Point::Point Point(size_t x, size_t y) const;

    size_t w_;
    size_t h_;
    std::vector<std::vector<bool>> maze_;
};


}
