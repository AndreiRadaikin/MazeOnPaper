#include "map.hpp"
#include <iostream>
#include <QPainter>
#include <QPen>
#include <iostream>
namespace Map {

std::map<Square::Capability, QPen> kPenMap = {
    {Square::Capability::NO, QPen(Qt::black)},
    {Square::Capability::YES, QPen({0, 0, 0, 20})},
    {Square::Capability::UNKNOWN, QPen({0,0,255, 90})},
};

Map::Map(QWidget *parent):QWidget(parent),square_w_(30),square_h_(30){
    this->setFixedSize(500, 500);

    // set background color
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, {141, 153, 204, 175});
    this->setAutoFillBackground(true);
    this->setPalette(Pal);
    kh = 11;
    kw = 11;
    this->setFixedSize(kw*square_w_ + 1, kh*square_h_+ 1);
}

Map::~Map()
{
}

void Map::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);
    QPainter painter(this);

    drawMaze(painter);


    painter.drawEllipse({WandererCenter().x_, WandererCenter().y_}, 5, 5);
}

void Map::moveWanderer(Point::Point v){
    wanderer_ += v;
    int upper_line = kh/-2;
    if(wanderer_.y_ - shift_.y_ == upper_line){
        shift_.y_--;
    }

    int under_line =kh/2 - 1;
    if(wanderer_.y_ - shift_.y_ == under_line){
        shift_.y_++;
    }

    int left_line = kw/-2;

    if(wanderer_.x_ - shift_.x_ == left_line){
        shift_.x_--;
    }

    int right_line = kw/2 - 1;
    if(wanderer_.x_ - shift_.x_ == right_line){
        shift_.x_++;
    }
}

Point::Point Map::GetOrigin() const {

    return Point::Point(this->width()/2, this->height()/2);
}

Point::Point Map::WandererCenter() const {
    auto rpos = wanderer_ - shift_;
    auto w_poz = Point::Point(rpos.x_*square_w_, rpos.y_*square_h_);
    if(!(kw%2))
        w_poz.x_+=square_w_/2;

    if(!(kh%2))
        w_poz.y_+=square_h_/2;
    return Point::Point(w_poz) + GetOrigin();
}

void Map::drawMaze(QPainter &painter){
    for(int y = 0; y < kh; ++y){
        for(int x = 0; x < kw; ++x){
            Point::Point position = Point::Point(x,y) + shift_ - Point::Point(kw/2, kh/2);
              Point::Point pixel = Point::Point(x * square_w_,y *square_h_);
            if(map_.find(position) != map_.end()){
                drawSquare(painter, pixel.x_,pixel.y_, map_[position]);
            } else {
                drawSquare(painter, pixel.x_,pixel.y_, Square::SquareInfo());
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

void Map::setUpCapability(Point::Point point, Square::Capability capability){
    Square::SquareInfo info = map_[point];
    info.passUp = capability;
    setCapability(point, info);
}

void Map::setDownCapability(Point::Point point, Square::Capability capability){
    Square::SquareInfo info = map_[point];
    info.passDown = capability;
    setCapability(point, info);
}

void Map::setLeftCapability(Point::Point point, Square::Capability capability){
    Square::SquareInfo info = map_[point];
    info.passLeft = capability;
    setCapability(point, info);
}

void Map::setRightCapability(Point::Point point, Square::Capability capability){
    Square::SquareInfo info = map_[point];
    info.passRight = capability;
    setCapability(point, info);
}

Point::Point Map::getPosition(){
    return  wanderer_;
}

}
