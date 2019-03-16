#include "maze.hpp"
#include <ctime>
namespace Maze {

Maze::Maze(size_t n): w_(6), h_(6),  maze_((h_ +5 ) *( w_ + 5), std::vector<bool>((h_ +5 ) *( w_ + 5), true)){
    srand(time(0));
    GenerateExternalWalls();
    GenerateInternalWalls();
    GenerateMazeWalls();
    for(size_t i = 0; i < n; ++i){
        GenerateTeleport();
    }
}

bool Maze::CanMoveFromTo(Point::Point from, Point::Point to) const {
    return maze_[V(from)][V(to)];
}

bool Maze::CanMoveFromTo(Point::Point from, Direction::Direction to) const {
    bool result = false;
    switch (to) {
    case Direction::Direction::UP:
        result = CanMoveFromTo(from, from + Point::Point(0,-1));
        break;
    case Direction::Direction::DOWN:
        result = CanMoveFromTo(from, from + Point::Point(0,1));
        break;
    case Direction::Direction::LEFT:
        result = CanMoveFromTo(from, from + Point::Point(-1,0));
        break;
    case Direction::Direction::RIGHT:
        result = CanMoveFromTo(from, from + Point::Point(1,0));
        break;
    default:
        result = false;
    }
    return result;
}

const std::vector<Point::Point> &Maze::GetTeleports() const {
    return teleports_;
}

FieldType::Type Maze::GetType(Point::Point point) const {
    return FieldType::Type::EMPTY;
}

void Maze::GenerateExternalWalls(){
    for(size_t y = 1; y < h_ + 3; ++y){
        SetWall(V(Point::Point(1, y)), V(Point::Point(0, y)));
        SetWall(V(Point::Point(w_ + 3, y)), V(Point::Point(w_ + 2, y)));
    }

    for(size_t x = 1; x < w_ + 3; ++x){
        SetWall(V(Point::Point(x, 1)), V(Point::Point(x, 0)));
        SetWall(V(Point::Point(x, h_ + 3)), V(Point::Point(x, h_ + 2)));
    }
}

void Maze::GenerateInternalWalls(){

    for(size_t y = 2; y < h_ + 2; ++y){
        SetWall(V(Point::Point(2, y)), V(Point::Point(1, y)));
        SetWall(V(Point::Point(w_ + 2, y)), V(Point::Point(w_ + 1, y)));
    }

    for(size_t x = 2; x < w_ + 2; ++x){
        SetWall(V(Point::Point(x, 2)), V(Point::Point(x, 1)));
        SetWall(V(Point::Point(x, h_ + 2)), V(Point::Point(x, h_ + 1)));
    }
}

void Maze::GenerateMazeWalls(){

}

void Maze::GenerateTeleport(){
    unsigned int n = rand() % 4;
    Point::Point teleport;
    switch (n) {
        case 0:{
            unsigned int x = rand() % w_ + 2;
            SetPass(V(Point::Point(x, 1)), V(Point::Point(x, 2)));
            SetWall(V(Point::Point(x - 1, 1)), V(Point::Point(x, 1)));
            SetWall(V(Point::Point(x + 1, 1)), V(Point::Point(x, 1)));
            teleports_.push_back(Point::Point(x,1));
            break;
        }
        case 1:{
            unsigned int y = rand() % h_ + 2;
            SetPass(V(Point::Point(w_ + 2, y)), V(Point::Point(w_ + 1, y)));
            SetWall(V(Point::Point(w_ + 2, y - 1)), V(Point::Point(w_ + 2, y)));
            SetWall(V(Point::Point(w_ + 2, y + 1)), V(Point::Point(w_ + 2, y)));
            teleports_.push_back(Point::Point(w_ + 2,y));
            break;
        }
        case 2: {
            unsigned int x = rand() % w_ + 2;
            SetPass(V(Point::Point(x, h_+2)), V(Point::Point(x, h_+1)));
            SetWall(V(Point::Point(x - 1, h_+2)), V(Point::Point(x, h_+2)));
            SetWall(V(Point::Point(x + 1, h_+2)), V(Point::Point(x, h_+2)));
            teleports_.push_back(Point::Point(x,h_+2));
            break;
        }
        case 3: {
            unsigned int y = rand() % h_ + 2;
            SetPass(V(Point::Point(1, y)), V(Point::Point(2, y)));
            SetWall(V(Point::Point(1, y - 1)), V(Point::Point(1, y)));
            SetWall(V(Point::Point(1, y + 1)), V(Point::Point(1, y)));
            teleports_.push_back(Point::Point(1,y));
            break;
        };
    default: break;
    }
}

size_t Maze::V(const Point::Point &point) const {
    if(point.x_ < 0 || point.y_ < 0){
        return  0;
    }
    size_t n = point.y_ * (w_ + 5) + point.x_;
    if(n >= maze_.size()){
        return  0;
    }
    return  n;
}

void Maze::SetWall(size_t from, size_t to) {
    maze_[from][to] = false;
    maze_[to][from] = false;
}

void Maze::SetPass(size_t from, size_t to) {
    maze_[from][to] = true;
    maze_[to][from] = true;
}

}

