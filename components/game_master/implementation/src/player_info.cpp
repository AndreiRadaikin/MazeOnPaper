#include "player_info.hpp"

namespace PlayerInfo {

PlayerInfo::PlayerInfo(size_t name):name_(name) {

}

PlayerInfo::PlayerInfo():name_(0) {

}

PlayerInfo::~PlayerInfo() {

}

size_t PlayerInfo::GetName() const {
    return  name_;
}

const Point::Point &PlayerInfo::GetPosition() const {
    return  position_;
}

void PlayerInfo::SetPosition(Point::Point position) {
    position_ = position;
}

void PlayerInfo::Move(Direction::Direction direction) {
    using Direction::Direction;
    switch (direction) {
    case Direction::RIGHT:
        position_+=Point::Point(1, 0);
        break;
    case Direction::LEFT:
        position_+=Point::Point(-1, 0);
        break;
    case Direction::UP:
        position_+=Point::Point(0, -1);
        break;
    case Direction::DOWN:
        position_+=Point::Point(0, 1);
        break;
    default:
        break;
    }
}

}
