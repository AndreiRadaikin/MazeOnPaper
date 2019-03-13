#pragma once

#include "step_request.hpp"

namespace Request {
class StepRequestImpl: public StepRequest {};
StepRequestPtr MakeStepRequestImpl();
} // Request
