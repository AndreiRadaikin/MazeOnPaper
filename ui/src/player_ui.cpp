#include "player_ui.hpp"
#include "QVBoxLayout"
#include <iostream>
namespace Player {

size_t Player::counter_;
PlayerUi::PlayerUi(QWidget *parent):QWidget(parent), name_(++Player::counter_), can_step_(false){
    auto layout = new QVBoxLayout(this);
    this->setLayout(layout);
    map_= new Map::Map(this);
    layout->addWidget(map_);
}

void PlayerUi::SetMaster(GameMaster::GameMasterPtr master){
    std::cout << name_ << " SetMaster(GameMaster::GameMasterPtr master)" << std::endl;
    master_ = master;
}

PlayerUi::~PlayerUi(){

}

size_t PlayerUi::Name() const {
    return  name_;
}

void PlayerUi::GameStartedNotify() {
    std::cout << name_ << " GameStartedNotify()" << std::endl;
}

void PlayerUi::YourMove() {
    std::cout << name_ << " YourMove()" << std::endl;
    can_step_ = true;
}

void PlayerUi::SwipeUp(){
    std::cout << "Up" << std::endl;
    map_->moveWanderer(Point::Point(0, -1));
    map_->update();
}

void PlayerUi::SwipeDpwn(){
    std::cout << "Down" << std::endl;
    map_->moveWanderer(Point::Point(0, 1));
    map_->update();
}

void PlayerUi::SwipeLeft(){
    std::cout << "Left" << std::endl;
    map_->moveWanderer(Point::Point(-1, 0));
    map_->update();
}

void PlayerUi::SwipeRight(){
    std::cout << "Right" << std::endl;
    map_->moveWanderer(Point::Point(1, 0));
    map_->update();
}

void PlayerUi::Tap(){
    std::cout << "Tap" << std::endl;
    can_step_ = false;
    master_->Finalize(name_ );
    map_->update();
}

void PlayerUi::keyPressEvent(QKeyEvent *event){
    int key=event->key();
    if(!can_step_) return;
    switch (key) {
    case Qt::Key::Key_Up: SwipeUp(); break;
    case Qt::Key::Key_Down: SwipeDpwn(); break;
    case Qt::Key::Key_Left: SwipeLeft(); break;
    case Qt::Key::Key_Right: SwipeRight(); break;
    case Qt::Key::Key_Space: Tap(); break;
    default:
        std::cout << "Non" << std::endl;
    }
}

}

