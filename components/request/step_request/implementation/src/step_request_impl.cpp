#include "step_request_impl.hpp"

namespace Request {

StepRequestPtr MakeStepRequestImpl(){
    return std::make_shared<StepRequestImpl>();
}
} // Request