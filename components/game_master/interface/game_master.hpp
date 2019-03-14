/*!
 * \file
 * \brief A header file with game master descriptions
 *
 * This file contains the definitions of the main
 * interface of the interaction with the game master
 * used in the game.
 */
#pragma once

#include <memory>
#include "player.hpp"
#include "action_request.hpp"
#include "interaction_request.hpp"
#include "step_request.hpp"
#include "action_response.hpp"
#include "interaction_response.hpp"
#include "step_response.hpp"

namespace GameMaster {

class GameMaster {
public:
    /*!
     * \brief Destructor GameMaster
     */
    virtual ~GameMaster() {}

    /*!
     * \brief Adds a player to the game
     * \param player Pointer to the player you want to add
     * \return true if player is added, otherwise false
     */
    virtual bool AddPlayer(Player::PlayerPtr player) = 0;

    /*!
     * \brief Step request
     * \param request Step request
     * \return Step Response
     */
    virtual Response::StepResponsePtr MakeStep(Request::StepRequestConstPtr request) = 0;

    /*!
     * \brief Reports that the player has completed the game
     */
    virtual void Finalize(size_t name) = 0;

    /*!
     * \brief Action request
     * \param request Action request
     * \return Action Response
     */
    virtual Response::ActionResponsePtr Action(Request::ActionRequestPtr request) = 0;

    /*!
     * \brief Interaction request
     * \param request Interaction request
     * \return Interaction Response
     */
    virtual Response::InteractionResponsePtr Interaction(Request::InteractionRequestPtr request) = 0;

    /*!
     * \brief Verifies the authenticity of gold
     * \return true if gold is real, otherwise it is false
     */
    virtual bool CheckGold() const = 0;
};

typedef std::shared_ptr<GameMaster> GameMasterPtr;
} // GameMaster
