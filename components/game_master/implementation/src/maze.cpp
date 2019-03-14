#include "maze.hpp"

namespace Maze {

bool Maze::CanMoveFromTo(Point::Point from, Point::Point to) const {
    return true;
}

bool Maze::CanMoveFromTo(Point::Point from, Direction::Direction to) const
{
    return true;
}

FieldType::Type Maze::GetType(Point::Point point) const {
    return FieldType::Type::EMPTY;
}

}

