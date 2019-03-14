#include "player_impl.hpp"
namespace Player {

PlayerPtr MakePlayerImpll(){
    return std::make_shared<PlayerImpl>();
}
}