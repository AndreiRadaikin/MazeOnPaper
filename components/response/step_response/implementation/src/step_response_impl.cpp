#include "step_response_impl.hpp"

namespace Response {

StepResponsePtr MakeStepResponseImpl(){
    return std::make_shared<StepResponseImpl>();
}
} // Response