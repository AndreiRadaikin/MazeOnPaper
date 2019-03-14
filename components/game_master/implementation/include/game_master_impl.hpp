#pragma once
#include <mutex>
#include "game_master.hpp"
#include "player_info.hpp"
#include "maze.hpp"

namespace GameMaster {
class GameMasterImpl: public GameMaster{
public:
    GameMasterImpl();
    ~GameMasterImpl();
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
    Response::StepResponsePtr MakeStep(Request::StepRequestConstPtr request) override; //TODO

    /*!
     * \brief Reports that the player has completed the game
     */
    void Finalize(size_t name) override;

    /*!
     * \brief Action request
     * \param request Action request
     * \return Action Response
     */
    Response::ActionResponsePtr Action(Request::ActionRequestPtr request) override; //TODO

    /*!
     * \brief Interaction request
     * \param request Interaction request
     * \return Interaction Response
     */
    Response::InteractionResponsePtr Interaction(Request::InteractionRequestPtr request) override; //TODO

    /*!
     * \brief Verifies the authenticity of gold
     * \return true if gold is real, otherwise it is false
     */
    bool CheckGold() const override; //TODO

private:
    void StartGame();
    bool IsCurrentPlayer(size_t name);

    Maze::Maze maze_;
    std::mutex protection_of_master_;
    Player::PlayersArray players_;
    PlayerInfo::PlayerInfoMap players_info_;
    const size_t max_players_;
    size_t current_players_numper_;
    size_t current_players_name_;
    bool step_maked_;
    bool action_;
    bool interaction_;
};

GameMasterPtr MakeGameMasterImpl();

} // GameMaster
