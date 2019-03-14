#pragma once

#include "player.hpp"

namespace Player
{
class PlayerImpl: public Player {
public:
    PlayerImpl();
    size_t Name() const override;
    void GameStartedNotify() override;
    void YourMove() override;
public:
    static size_t counter_;
    const size_t name_;;
};
PlayerPtr MakePlayerImpll();
} // Player
