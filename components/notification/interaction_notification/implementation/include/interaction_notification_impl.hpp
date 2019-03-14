#pragma once

#include "interaction_notification.hpp"

namespace Notification {
class InteractionNotificationImpl: public InteractionNotification {};
InteractionNotificationPtr MakeInteractionNotificationImpl();

} 
