#pragma once
#include <iostream>
#include <vector>
#include "point.hpp"
#include "direction.hpp"
#include "field_type.hpp"

namespace Maze {

class Maze {
public:
    explicit Maze(size_t n);
    bool CanMoveFromTo(Point::Point from, Point::Point to) const;
    bool CanMoveFromTo(Point::Point from, Direction::Direction to) const;
    const std::vector<Point::Point> &GetTeleports() const;
    FieldType::Type GetType(Point::Point point) const;
private:
    Maze();
    void GenerateExternalWalls();
    void GenerateInternalWalls();
    void GenerateMazeWalls();
    void GenerateTeleport();

    size_t V(const Point::Point &point) const;
    void SetWall(size_t from, size_t to);
    void SetPass(size_t from, size_t to);
//    Point::Point Point(size_t x, size_t y) const;

    size_t w_;
    size_t h_;
    std::vector<Point::Point> teleports_;
    std::vector<std::vector<bool>> maze_;
};


}
