#include "player_impl.hpp"
namespace Player {

size_t PlayerImpl::counter_ = 0;

PlayerPtr MakePlayerImpll(){
    return std::make_shared<PlayerImpl>();
}

PlayerImpl::PlayerImpl():name_(++counter_){

}

size_t PlayerImpl::Name() const{
    return name_;
}

void PlayerImpl::GameStartedNotify(){

}

void PlayerImpl::YourMove(){

}

}
