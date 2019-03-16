#include "player_ui.hpp"
#include "QVBoxLayout"
#include <iostream>
#include "step_request_impl.hpp"
#include "step_response.hpp"
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
    this->activateWindow();
    can_step_ = true;
}

void PlayerUi::SwipeUp(){
    std::cout << "Up" << std::endl;
    Response::StepResponsePtr responce =
            master_->MakeStep(Request::MakeStepRequestImpl(name_, Direction::Direction::UP));
    auto result = responce->GetResult();
    switch (result) {
        case StepResult::Result::SUCCESS:
            map_->setUpCapability(map_->getPosition(), Square::Capability::YES);
            map_->moveWanderer(Point::Point(0, -1));
        break;
        case StepResult::Result::WALL:
            map_->setUpCapability(map_->getPosition(), Square::Capability::NO);
        break;
    default:
        return;
    }
    map_->update();
}

void PlayerUi::SwipeDpwn(){
    std::cout << "Down" << std::endl;
    Response::StepResponsePtr responce =
            master_->MakeStep(Request::MakeStepRequestImpl(name_, Direction::Direction::DOWN));
    auto result = responce->GetResult();
    switch (result) {
        case StepResult::Result::SUCCESS:
            map_->setDownCapability(map_->getPosition(), Square::Capability::YES);
            map_->moveWanderer(Point::Point(0, 1));
        break;
        case StepResult::Result::WALL:
            map_->setDownCapability(map_->getPosition(), Square::Capability::NO);
        break;
    default:
        return;
    }
    map_->update();
}

void PlayerUi::SwipeLeft(){
    std::cout << "Left" << std::endl;
    Response::StepResponsePtr responce =
            master_->MakeStep(Request::MakeStepRequestImpl(name_, Direction::Direction::LEFT));
    auto result = responce->GetResult();
    switch (result) {
        case StepResult::Result::SUCCESS:
            map_->setLeftCapability(map_->getPosition(), Square::Capability::YES);
            map_->moveWanderer(Point::Point(-1, 0));
        break;
        case StepResult::Result::WALL:
            map_->setLeftCapability(map_->getPosition(), Square::Capability::NO);
        break;
    default:
        return;
    }
    map_->update();
}

void PlayerUi::SwipeRight(){
    std::cout << "Right" << std::endl;
    Response::StepResponsePtr responce =
            master_->MakeStep(Request::MakeStepRequestImpl(name_, Direction::Direction::RIGHT));
    auto result = responce->GetResult();
    switch (result) {
        case StepResult::Result::SUCCESS:
            map_->setRightCapability(map_->getPosition(), Square::Capability::YES);
            map_->moveWanderer(Point::Point(1, 0));
        break;
        case StepResult::Result::WALL:
            map_->setRightCapability(map_->getPosition(), Square::Capability::NO);
        break;
    default:
        return;
    }
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
    Tap();
}

}

