
#include "step_notification_impl.hpp"

namespace Notification {

StepNotificationPtr MakeStepNotificationImpl(){
    return std::make_shared<StepNotificationImpl>();
}
} 