#pragma once

#include <memory>

namespace Notification {
    class ActionNotification {};
    typedef std::shared_ptr<ActionNotification> ActionNotificationPtr;
} //Notification