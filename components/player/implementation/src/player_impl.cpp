#include "player_impl.hpp"
namespace Player {
size_t Player::counter_;
PlayerPtr MakePlayerImpll(){
    return std::make_shared<PlayerImpl>();
}

PlayerImpl::PlayerImpl():name_(++Player::counter_){

}

size_t PlayerImpl::Name() const{
    return name_;
}

void PlayerImpl::GameStartedNotify(){

}

void PlayerImpl::YourMove(){

}

}
