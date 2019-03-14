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

namespace Player {
class Player {};
typedef std::shared_ptr<Player> PlayerPtr;
} // Player
