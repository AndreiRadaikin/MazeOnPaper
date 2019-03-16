#pragma once
#include <map>
#include <iostream>
#include "point.hpp"
#include "direction.hpp"

namespace PlayerInfo {

class PlayerInfo{
public:
    PlayerInfo(size_t name);
    PlayerInfo();
    ~PlayerInfo();
    size_t GetName() const;
    const Point::Point&  GetPosition() const;
    void SetPosition(Point::Point position);
    void Move(Direction::Direction direction);
    bool operator > (const PlayerInfo& p){
        return name_ > p.name_;
    }
private:
    size_t name_;
    Point::Point position_;

};

typedef std::map<size_t, PlayerInfo> PlayerInfoMap;
} // PlayerInfo
