#pragma once
#include <QWidget>
#include <QPaintEvent>
#include <map>
#include "point.hpp"

namespace Square {
enum class Capability { YES, NO, UNKNOWN };
struct SquareInfo{
SquareInfo():   passUp(Capability::UNKNOWN),
                passDown(Capability::UNKNOWN),
                passLeft(Capability::UNKNOWN),
                passRight(Capability::UNKNOWN){}
SquareInfo(Capability up, Capability down, Capability left, Capability right):
                passUp(up),
                passDown(down),
                passLeft(left),
                passRight(right){}
Capability passUp;
Capability passDown;
Capability passLeft;
Capability passRight;
};
}

namespace Map {
class Map: public QWidget{
Q_OBJECT
public:
    explicit Map(QWidget *parent = nullptr);
    ~Map();
    virtual void paintEvent(QPaintEvent *e);
    void moveWanderer(Point::Point v);
    void setCapability(Point::Point point, Square::SquareInfo info);
    void setUpCapability(Point::Point point, Square::Capability capability);
    void setDownCapability(Point::Point point, Square::Capability capability);
    void setLeftCapability(Point::Point point, Square::Capability capability);
    void setRightCapability(Point::Point point, Square::Capability capability);

    Point::Point getPosition();
private:
    Point::Point GetOrigin() const;
    Point::Point WandererCenter() const;
    void drawMaze(QPainter& painter);
    void drawSquare(QPainter& painter, int x, int y, const Square::SquareInfo& info);
    const int square_w_;
    const int square_h_;
    int kh;
    int kw;
    Point::Point shift_;
    std::map<Point::Point, Square::SquareInfo> map_;
    Point::Point wanderer_;
};
}
