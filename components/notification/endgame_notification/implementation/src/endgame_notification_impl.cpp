
#include "endgame_notification_impl.hpp"

namespace Notification {

EndgameNotificationPtr MakeEndgameNotificationImpl(){
    return std::make_shared<EndgameNotificationImpl>();
}
} 