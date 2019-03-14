#pragma once

#include "endgame_notification.hpp"

namespace Notification {
class EndgameNotificationImpl: public EndgameNotification {};
EndgameNotificationPtr MakeEndgameNotificationImpl();

} 
