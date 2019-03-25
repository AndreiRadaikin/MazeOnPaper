#include "recurcive_maze_generator.hpp"
#include <ctime>
#include <math.h>
#include <windows.h>
namespace Maze {

RecurciveMazeGenerator::RecurciveMazeGenerator(std::vector<std::vector<bool>>& maze):maze_(maze)
{

}

void RecurciveMazeGenerator::gen(size_t w, size_t h, std::vector<std::vector<bool>>& maze)
{
    w_ = w;
    h_ = h;
    n_ = 0;
    maze_ = maze;
    srand(time(NULL));
    GenerateExternalWalls();
    GenerateMazeWalls(Point::Point(2, 2), Point::Point (h_ + 2, w_ + 2));
}

void RecurciveMazeGenerator::GenerateExternalWalls(){
    for(size_t y = 1; y < h_ + 2; ++y){
        SetWall(V(Point::Point(1, y)), V(Point::Point(2, y)));
        SetWall(V(Point::Point(w_ + 1, y)), V(Point::Point(w_ + 2, y)));
    }
    for(size_t x = 1; x < w_ + 2; ++x){
        SetWall(V(Point::Point(x, 1)), V(Point::Point(x, 2)));
        SetWall(V(Point::Point(x, h_ + 1)), V(Point::Point(x, h_ + 2)));
    }
    printMaze();
}

void RecurciveMazeGenerator::GenerateMazeWalls(Point::Point p1, Point::Point p2){
    Point::Point middlePoint = GetMiddlePoint(p1,p2);
    std::cout << middlePoint  << std::endl;



        switch (n_) {
            case 0:{
        for(size_t y = p1.y_; y <= p2.y_; ++y){
            SetWall(V(Point::Point(middlePoint.x_,y)), V(Point::Point(middlePoint.x_ + 1,y)));
        }
        if(std::abs(p1.y_ - p2.y_) > 1){
        MakeVerticalPass(Point::Point(middlePoint.x_, p1.y_ + (rand()% (middlePoint.y_ - p1.y_))));
        } else{

        }
        std::cout<< "Made vert pass" <<std::endl;
        printMaze();
        n_ = 1;
        break;
        }
        case 1:{
        for(size_t x = p1.x_; x <= p2.x_; ++x){
            SetWall(V(Point::Point(x,middlePoint.y_)), V(Point::Point(x,middlePoint.y_ + 1)));
        }
        printMaze();
//        MakeHorizontalPass(Point::Point(p1.x_ + (rand()% (middlePoint.x_ - p1.x_)), middlePoint.y_));
        n_ = 0;
        break;
        }
        }
        if(std::abs(p1.x_ - p2.x_) ==  1 ||  std::abs(p1.y_ - p2.y_) == 1) return;
        GenerateMazeWalls(p1, middlePoint);

        GenerateMazeWalls(Point::Point(middlePoint.x_,p1.y_),Point::Point(p2.x_,middlePoint.y_));
        GenerateMazeWalls(Point::Point(p1.x_,middlePoint.y_),Point::Point(middlePoint.x_,p2.y_));
        GenerateMazeWalls(middlePoint, p2);

}

Point::Point RecurciveMazeGenerator::GetMiddlePoint(Point::Point p1, Point::Point p2){
    return Point::Point((p1.x_ + p2.x_) / 2, (p1.y_ + p2.y_) / 2);
}

void RecurciveMazeGenerator::MakeHorizontalPass(Point::Point p){
    SetPass(V(Point::Point(p.x_, p.y_)), V(Point::Point(p.x_, p.y_ + 1)));

}
void RecurciveMazeGenerator::MakeVerticalPass(Point::Point p){
    SetPass(V(Point::Point(p.x_, p.y_)), V(Point::Point(p.x_ + 1, p.y_)));
}

size_t RecurciveMazeGenerator::V(const Point::Point &point) const {
    if(point.x_ < 0 || point.y_ < 0){
        return  0;
    }
    size_t n = point.y_ * (w_ + 5) + point.x_;
    if(n >= maze_.size()){
        return  0;
    }
    return  n;
}

void RecurciveMazeGenerator::SetWall(size_t from, size_t to) {
    maze_[from][to] = false;
    maze_[to][from] = false;
}

void RecurciveMazeGenerator::SetPass(size_t from, size_t to) {
    maze_[from][to] = true;
    maze_[to][from] = true;
}

void RecurciveMazeGenerator::printMaze(){

    std::cout << "=============================================================" << std::endl;
    for(size_t y = 0; y < h_+3; ++y){
        for(size_t x = 0; x < w_+ 4; ++x){
            if(CanMoveFromTo(Point::Point(x - 1 , y), Point::Point(x, y))){
                std::cout << " ";
            } else std::cout << "|";
            if(CanMoveFromTo(Point::Point(x, y), Point::Point(x, y + 1))){
                std::cout << "  ";
            } else std::cout << "__";
        }
        std::cout << std::endl;
    }
    std::cout << "\n=============================================================" << std::endl;
}

bool RecurciveMazeGenerator::CanMoveFromTo(Point::Point from, Point::Point to) const {
    return maze_[V(from)][V(to)];
}
}
