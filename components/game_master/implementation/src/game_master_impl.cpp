#include "game_master_impl.hpp"

namespace GameMaster {
GameMasterPtr MakeGameMasterImpl() {
    return std::make_shared<GameMasterImpl>();
}
} //GameMaster
