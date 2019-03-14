
#include <iostream>
#include <map>
#include <string>
#include <functional>
#include <vector>
#include <game_master.hpp>
#include <game_master_impl.hpp>
#include <player_impl.hpp>

std::map<std::string, std::function<bool()>> tests = {
{"Make master", [](){
    GameMaster::GameMasterPtr master = GameMaster::MakeGameMasterImpl();
    return true;
}},
{"AddPlayer", [](){
    GameMaster::GameMasterPtr master = GameMaster::MakeGameMasterImpl();
    const bool add_player_1 = master->AddPlayer(Player::MakePlayerImpll());
    const bool add_player_2 = master->AddPlayer(Player::MakePlayerImpll());
    const bool add_player_3 = master->AddPlayer(Player::MakePlayerImpll());
    return add_player_1 && add_player_2 && !add_player_3;
}},
};

int main(){
    std::cout << "Game Master test" << std::endl;
    size_t n = 0;
    std::vector<std::string>failed;
    for(const auto& test: tests){
        std::cout << ++n << "/" << tests.size() <<  " Test: " << test.first<<std::endl;
        bool result = test.second();
        if(!result) failed.push_back(test.first);
        std::cout << n << "/" << tests.size()<< " Result: " << (result?"SUCCESS":"FAIL") << std::endl;
    }
    std::cout << "Failed " << failed.size() << " from " << tests.size() << std::endl;
    for(const auto& name : failed){
        std::cout << "      " << name << std::endl;
    }
    return 0;
}
