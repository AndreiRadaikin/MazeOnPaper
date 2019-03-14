#pragma once

#include "player.hpp"

namespace Player
{
class PlayerImpl: public Player {};
PlayerPtr MakePlayerImpll();
} // Player
