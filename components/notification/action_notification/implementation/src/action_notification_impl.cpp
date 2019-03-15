
#include "action_notification_impl.hpp"

namespace Notification {

ActionNotificationPtr MakeNotificationRequestImpl(){
    return std::make_shared<ActionNotificationImpl>();

}
} 
