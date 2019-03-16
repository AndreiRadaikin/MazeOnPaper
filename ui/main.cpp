#include <iostream>
#include <QtWidgets/QApplication>
#include "player_ui.hpp"
#include <memory>
#include <game_master_impl.hpp>

int main(int argc, char **argv){
    std::cout << "Hello Maze" << std::endl;
    GameMaster::GameMasterPtr master = GameMaster::MakeGameMasterImpl();

    QApplication aplication(argc, argv);
    std::shared_ptr<Player::PlayerUi> player1 = std::make_shared<Player::PlayerUi>();
    std::shared_ptr<Player::PlayerUi> player2 = std::make_shared<Player::PlayerUi>();
    std::shared_ptr<Player::PlayerUi> player3 = std::make_shared<Player::PlayerUi>();

    if(master->AddPlayer(player1)){
        player1->SetMaster(master);
    };
    if(master->AddPlayer(player2)){
        player2->SetMaster(master);
    };
    if(master->AddPlayer(player3)){
        player3->SetMaster(master);
    };

    player1->show();
    player2->show();
    return aplication.exec();
}
