#pragma once
#include "game_master.hpp"

namespace GameMaster {

class GameMasterImpl: public GameMaster{
public:
    /*!
     * \brief Adds a player to the game
     * \param player Pointer to the player you want to add
     * \return true if player is added, otherwise false
     */
    bool AddPlayer(Player::PlayerPtr player) override;

    /*!
     * \brief Step request
     * \param request Step request
     * \return Step Response
     */
    Response::StepResponsePtr MakeStep(Request::StepRequest Request) override;

    /*!
     * \brief Reports that the player has completed the game
     */
    void Finalize() override;

    /*!
     * \brief Action request
     * \param request Action request
     * \return Action Response
     */
    Response::ActionResponsePtr Action(Request::ActionRequestPtr request) override;

    /*!
     * \brief Interaction request
     * \param request Interaction request
     * \return Interaction Response
     */
    Response::InteractionResponsePtr Interaction(Request::InteractionRequestPtr request) override;

    /*!
     * \brief Verifies the authenticity of gold
     * \return true if gold is real, otherwise it is false
     */
    bool CheckGold() const override;
};

GameMasterPtr MakeGameMasterImpl();

} // GameMaster
