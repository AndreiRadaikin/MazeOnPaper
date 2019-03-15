#pragma once

#include "action_notification.hpp"

namespace Notification {
class ActionNotificationImpl: public ActionNotification {};
ActionNotificationPtr MakeActionNotificationImpl();
}
