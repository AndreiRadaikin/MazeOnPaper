#include "maze.hpp"

namespace Maze {

Maze::Maze():w_(6),h_(6),  maze_((h_ +5 ) *( w_ + 5), std::vector<bool>((h_ +5 ) *( w_ + 5), false)){

  for(size_t y = 1; y < h_ + 3; ++y){
    SetWall(V(Point::Point(1, y)), V(Point::Point(0, y)));
    SetWall(V(Point::Point(w_ + 3, y)), V(Point::Point(w_ + 2, y)));
  }

  for(size_t x = 1; x < w_ + 3; ++x){
    SetWall(V(Point::Point(x, 1)), V(Point::Point(x, 0)));
    SetWall(V(Point::Point(x, h_ + 3)), V(Point::Point(x, h_ + 2)));
  }

  for(size_t y = 2; y < h_ + 2; ++y){
    SetWall(V(Point::Point(2, y)), V(Point::Point(1, y)));
    SetWall(V(Point::Point(w_ + 2, y)), V(Point::Point(w_ + 1, y)));
  }

  for(size_t x = 2; x < w_ + 2; ++x){
    SetWall(V(Point::Point(x, 2)), V(Point::Point(x, 1)));
    SetWall(V(Point::Point(x, h_ + 2)), V(Point::Point(x, h_ + 1)));
  }
}

bool Maze::CanMoveFromTo(Point::Point from, Point::Point to) const {
    return !maze_[V(from)][V(to)];
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

FieldType::Type Maze::GetType(Point::Point point) const {
    return FieldType::Type::EMPTY;
}

size_t Maze::V(const Point::Point &point) const {
    if(point.x_ < 0 || point.y_ < 0){
        std::cout << "Warning!!" << std::endl;
        return  0;
    }
    size_t n = point.y_ * (w_ + 5) + point.x_;
    if(n >= maze_.size()){
        return  0;

    }
    return  n;
}

void Maze::SetWall(size_t from, size_t to){
    std::cout << "from " << from << " to "<< to << std::endl;
    maze_[from][to] = true;
    maze_[to][from] = true;
}

}

