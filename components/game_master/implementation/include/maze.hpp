#pragma once

#include "point.hpp"
#include "direction.hpp"
#include "field_type.hpp"

namespace Maze {

class Maze {
public:
    Maze() {}
    bool CanMoveFromTo(Point::Point from, Point::Point to) const;
    bool CanMoveFromTo(Point::Point from, Direction::Direction to) const;
    FieldType::Type GetType(Point::Point point) const;
};

}
