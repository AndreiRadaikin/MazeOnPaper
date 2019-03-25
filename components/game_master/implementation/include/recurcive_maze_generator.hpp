#pragma once
#include <iostream>
#include <vector>
#include <point.hpp>

namespace Maze {
class RecurciveMazeGenerator{
public:
    RecurciveMazeGenerator(std::vector<std::vector<bool> > &maze);
    void gen(size_t w, size_t h, std::vector<std::vector<bool>>& maze);
private:
    void printMaze();
    bool CanMoveFromTo(Point::Point from, Point::Point to) const;
    void GenerateExternalWalls();
    void GenerateMazeWalls(Point::Point p1, Point::Point p2);

    Point::Point GetMiddlePoint(Point::Point p1, Point::Point p2);

    void MakeHorizontalPass(Point::Point p);
    void MakeVerticalPass(Point::Point p);

    size_t V(const Point::Point &point) const;


    void SetWall(size_t from, size_t to);
    void SetPass(size_t from, size_t to);

     size_t w_;
     size_t h_;
     size_t n_;

     std::vector<std::vector<bool>>& maze_;
};
}
