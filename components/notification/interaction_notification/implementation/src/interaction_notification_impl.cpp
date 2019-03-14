
#include "interaction_notification_impl.hpp"

namespace Notification {

InteractionNotificationPtr MakeInteractionNotificationImpl(){
    return std::make_shared<InteractionNotificationImpl>();
}
} 