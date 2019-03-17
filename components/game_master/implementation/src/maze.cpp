#include "maze.hpp"
#include <ctime>
namespace Maze {

Maze::Maze(size_t n): w_(10), h_(10),  maze_((h_ +5 ) *( w_ + 5), std::vector<bool>((h_ +5 ) *( w_ + 5), true)){
    srand(time(nullptr));
    GenerateExternalWalls();
    GenerateInternalWalls();
    GenerateMazeWalls();
    for(size_t i = 0; i < n; ++i){
        GenerateTeleport();
    }
    printMaze();
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

void Maze::printMaze(){

    std::cout << "=============================================================" << std::endl;
    for(size_t y = 0; y < h_+3; ++y){
        for(size_t x = 1; x < w_+4; ++x){
            if(CanMoveFromTo(Point::Point(x -1, y), Point::Point(x, y))){
                std::cout << " ";
            } else std::cout << "|";
            if(CanMoveFromTo(Point::Point(x, y + 1), Point::Point(x, y))){
                std::cout << "  ";
            } else std::cout << "__";
        }
        std::cout << std::endl;
    }
    std::cout << "\n=============================================================" << std::endl;
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
    size_t counter = 0;
    std::vector<std::vector<size_t>> group(h_+5, std::vector<size_t>(w_+5, 0));

    for(size_t y = 2; y < h_ + 2; ++y){
        setGroup(group, y, counter);
        setVerticalWalls(group[y],y);
        setHorisontalWalls(group[y],y);
    }
    destroyWals(group[h_+1],h_+1);
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

void Maze::setGroup(std::vector<std::vector<size_t> > &group, size_t line, size_t &counter){
    for(size_t x = 2; x< w_ + 2; ++x){
        if(CanMoveFromTo(Point::Point(x, line - 1), Point::Point(x, line))){
            auto g = group[line - 1][x];
            if(g == 0){
                group[line][x] = g;
            }
            group[line][x] = g;
        } else {
            group[line][x] = ++counter;
        }
    }
}

void Maze::setVerticalWalls(std::vector<size_t> &group, size_t line){
    const bool makeLoop = false;
    for(size_t x = 2; x< w_ + 1; ++x){
        if(group[x] == group[x + 1] && !makeLoop){
            SetWall(V(Point::Point(x,line)), V(Point::Point(x + 1,line)));
        } else {
            if(rand() % 2){
                SetWall(V(Point::Point(x,line)), V(Point::Point(x + 1,line)));
            } else {
                mergGroup(group, group[x], group[x + 1]);
            }
        }
    }
}

size_t Maze::mergGroup(std::vector<size_t> &group, size_t g1, size_t g2){
    size_t last = 0;
    for(size_t x = 2; x <  w_ + 2; ++x){
        if(group[x] == g2){
            group[x] = g1;
            last = x;
        }
    }
    return last - 1;
}

void Maze::setHorisontalWalls(std::vector<size_t> &group, size_t line){
    bool ch = false;
    for(size_t x = 2; x < w_ + 2; ++x){
        if(group[x] == group[x + 1] || ch){
            if(rand() % 2){
                SetWall(V(Point::Point(x,line)),V(Point::Point(x,line + 1)));
                ch |= false;
            } else ch |= true;
        }
        if(group[x] == group[x + 1]) ch = false;
    }
}

void Maze::destroyWals(std::vector<size_t> &group, size_t line){
    for(size_t x = 2; x< w_ + 1; ++x){
        if(group[x] != group[x + 1]){
            SetPass(V(Point::Point(x, line)), V(Point::Point(x+ 1, line)));
        }
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

