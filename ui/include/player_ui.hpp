#pragma once
#include <qt5/QtWidgets/QWidget>
#include <QKeyEvent>
#include "map.hpp"
#include "player.hpp"
#include "game_master.hpp"

namespace Player {

class PlayerUi: public QWidget, public Player {
Q_OBJECT
public:
    explicit PlayerUi(QWidget *parent = nullptr);
    void SetMaster(GameMaster::GameMasterPtr master);
    ~PlayerUi();
private:
    virtual size_t Name() const override;
    virtual void GameStartedNotify() override;
    virtual void YourMove() override;

    void SwipeUp();
    void SwipeDpwn();
    void SwipeLeft();
    void SwipeRight();
    void Tap();
    virtual void keyPressEvent(QKeyEvent *event) override;


    Map::Map* map_;
    const size_t name_;
    GameMaster::GameMasterPtr master_;
    bool can_step_;
};
}
