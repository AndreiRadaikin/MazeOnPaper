#include "map.hpp"
#include <iostream>
#include <QPainter>
#include <QPen>
#include <iostream>
namespace Map {

std::map<Square::Capability, QPen> kPenMap={
    {Square::Capability::NO, QPen(Qt::black)},
    {Square::Capability::YES, QPen({0, 0, 0, 0})},
    {Square::Capability::UNKNOWN, QPen({0,0,255, 50})},
};

Map::Map(QWidget *parent):QWidget(parent),square_w_(30),square_h_(30){
    std::cout << "Map(QWidget *parent = " << parent << " )" <<std::endl;
    this->setFixedSize(500, 500);

    // set background color
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, {141, 153, 204, 150});
    this->setAutoFillBackground(true);
    this->setPalette(Pal);
    kh = 12;
    kw = 12;
    this->setFixedSize(kw*square_w_ + 1, kh*square_h_+ 1);

    using namespace Square;
    setCapability(Point::Point(0, 0), SquareInfo(Capability::YES,Capability::NO,Capability::NO,Capability::NO));

}

Map::~Map()
{
    std::cout << "~Map()" <<std::endl;
}

void Map::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);
    QPainter painter(this);

    drawMaze(painter);


    painter.drawEllipse({WandererCenter().x_, WandererCenter().y_}, 5, 5);
}

void Map::moveWanderer(Point::Point v){
    wanderer_ += v;
}

Point::Point Map::GetOrigin() const {

    return Point::Point(this->width()/2, this->height()/2);
}

Point::Point Map::WandererCenter() const {
    auto w_poz = Point::Point(wanderer_.x_*square_w_, wanderer_.y_*square_h_);
    if(!(kw%2))
        w_poz.x_+=square_w_/2;

    if(!(kh%2))
        w_poz.y_+=square_h_/2;
    return Point::Point(w_poz) + GetOrigin();
}

void Map::drawMaze(QPainter &painter){
    for(int y = 0; y < this->height(); y+=square_h_){
        for(int x = 0; x < this->width(); x+=square_w_){
            Point::Point position = Point::Point(x,y) - GetOrigin();
            position.x_/=square_w_;
            position.y_/=square_h_;
            if(map_.find(position) != map_.end()){
                drawSquare(painter, x,y, map_[position]);
            } else {
                drawSquare(painter, x,y, Square::SquareInfo());
            }
        }
    }
}

void Map::drawSquare(QPainter &painter, int x, int y, const Square::SquareInfo &info){
//    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    painter.setPen(kPenMap[info.passUp]);
    painter.drawLine(x, y, x + square_w_, y);

    painter.setPen(kPenMap[info.passDown]);
    painter.drawLine(x, y + square_h_, x + square_w_, y + square_h_);

    painter.setPen(kPenMap[info.passLeft]);
    painter.drawLine(x, y, x, y + square_w_);

    painter.setPen(kPenMap[info.passRight]);
    painter.drawLine(x + square_w_, y, x + square_w_, y + square_h_);

    painter.setPen(QPen());
}

void Map::setCapability(Point::Point point, Square::SquareInfo info){
    using Square::Capability;
    using Point::Point;
    map_[point] = info;
    map_[point + Point(0, 1)].passUp = info.passDown;
    map_[point + Point(0, -1)].passDown = info.passUp;
    map_[point + Point(1, 0)].passLeft = info.passRight;
    map_[point + Point(-1, 0)].passRight = info.passLeft;
}

}
