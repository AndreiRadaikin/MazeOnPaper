#pragma once

#include "step_notification.hpp"

namespace Notification {
class StepNotificationImpl: public StepNotification {};
StepNotificationPtr MakeStepNotificationImpl();

} 
