#include "game_master_impl.hpp"
#include "player_impl.hpp"
#include "step_request_impl.hpp"
#include "step_response_impl.hpp"
#include "action_request_impl.hpp"
#include "action_response_impl.hpp"
#include "interaction_request_impl.hpp"
#include "interaction_response_impl.hpp"
#include "field_type.hpp"

typedef std::lock_guard<std::mutex> AutoLock;

const size_t kMaxPlayers = 1;

namespace GameMaster {
GameMasterPtr MakeGameMasterImpl() {
    return std::make_shared<GameMasterImpl>();
}

GameMasterImpl::GameMasterImpl():maze_(kMaxPlayers), max_players_(kMaxPlayers), current_players_numper_(0),step_maked_(false),action_(false),interaction_(false){
}

GameMasterImpl::~GameMasterImpl(){
}

bool GameMasterImpl::AddPlayer(Player::PlayerPtr player){
    AutoLock auto_lock(protection_of_master_);
    if(players_.size() >= max_players_){
        return false;
    }
    players_info_[player->Name()] = PlayerInfo::PlayerInfo(player->Name());
    players_info_[player->Name()].SetPosition(maze_.GetTeleports()[players_.size()]);
    players_.push_back(player);
    if(players_.size() == max_players_){
        StartGame();
    }
    return true;
}

Response::StepResponsePtr GameMasterImpl::MakeStep(Request::StepRequestConstPtr request){
    AutoLock auto_lock(protection_of_master_);
    if(current_players_name_ != request->GetName() || step_maked_){
        return Response::MakeStepResponseImpl(StepResult::Result::FAIL, FieldType::Type::INVALID);
    }
    const auto& player_position = players_info_[current_players_name_].GetPosition();
    if(!maze_.CanMoveFromTo(player_position,request->GetDirection())){
        return Response::MakeStepResponseImpl(StepResult::Result::WALL, FieldType::Type::INVALID);
    }
    players_info_[current_players_name_].Move(request->GetDirection());
    step_maked_ = true;
    return Response::MakeStepResponseImpl(StepResult::Result::SUCCESS, maze_.GetType(player_position));
}

void GameMasterImpl::Finalize(size_t name){
    AutoLock auto_lock(protection_of_master_);
    if(!IsCurrentPlayer(name)){
        return;
    };
    ++current_players_numper_%=players_.size();
    current_players_name_ = players_[current_players_numper_]->Name();
    players_[current_players_numper_]->YourMove();
    step_maked_ = false;
    action_ = false;
    interaction_ = false;
}

Response::ActionResponsePtr GameMasterImpl::Action(Request::ActionRequestPtr request){
    AutoLock auto_lock(protection_of_master_);
    return Response::MakeActionResponseImpl();
}

Response::InteractionResponsePtr GameMasterImpl::Interaction(Request::InteractionRequestPtr request){
    AutoLock auto_lock(protection_of_master_);
    return  Response::MakeInteractionResponseImpl();
}

bool GameMasterImpl::CheckGold() const {
    return false;
}

void GameMasterImpl::StartGame() {
    for(auto& player: players_){
        player->GameStartedNotify();
    }
    current_players_name_ = players_[current_players_numper_]->Name();
    players_[current_players_numper_]->YourMove();
}

bool GameMasterImpl::IsCurrentPlayer(size_t name){
    return name == current_players_name_;
}

} //GameMaster
