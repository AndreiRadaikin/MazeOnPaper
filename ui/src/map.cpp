#include "map.hpp"
#include <iostream>
#include <QPainter>
#include <QPen>
#include <iostream>
namespace Map {

std::map<Square::Capability, QPen> kPenMap = {
    {Square::Capability::NO, QPen(Qt::black)},
    {Square::Capability::YES, QPen({0, 0, 0, 0})},
    {Square::Capability::UNKNOWN, QPen({0,0,255, 50})},
};

Map::Map(QWidget *parent):QWidget(parent),square_w_(30),square_h_(30){
    this->setFixedSize(500, 500);

    // set background color
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, {141, 153, 204, 150});
    this->setAutoFillBackground(true);
    this->setPalette(Pal);
    kh = 12;
    kw = 12;
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
    auto& wy = wanderer_.y_;
    auto& sy = shift_.y_;
    int k = kh/2 - 3;
    if(wy > k) {
        sy = wy - k;
    } else if(wy < k * -1) {
        sy = wy + k;
    }
    else sy = 0;

    k = kw/2 - 3;
    auto& wx = wanderer_.x_;
    auto& sx = shift_.x_;
    if(wx > k){
        sx = wx - k;
    } else if(wx < k * -1){
        sx = wx + k;
    }
    else sx = 0;

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
    for(int y = 0; y < this->height(); y+=square_h_){
        for(int x = 0; x < this->width(); x+=square_w_){
            Point::Point position = Point::Point(x,y) - GetOrigin();
            position.x_/=square_w_;
            position.y_/=square_h_;
            position += shift_;
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
