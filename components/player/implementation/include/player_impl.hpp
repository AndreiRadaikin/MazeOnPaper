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
    const size_t name_;
};
PlayerPtr MakePlayerImpll();
} // Player
