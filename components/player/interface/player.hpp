/*!
 * \file
 * \brief A header file with player descriptions
 *
 * This file contains the definitions of the main
 * interface of the interaction with the player
 * used in the game.
 */
#pragma once

#include <memory>
#include <vector>

namespace Player {
class Player {
public:
    virtual ~Player(){}
    virtual size_t Name() const = 0;
    virtual void GameStartedNotify() = 0;
    virtual void YourMove() = 0;
};
typedef std::shared_ptr<Player> PlayerPtr;
typedef std::vector<PlayerPtr> PlayersArray;
} // Player
