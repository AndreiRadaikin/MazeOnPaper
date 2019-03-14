#pragma once

#include "step_response.hpp"

namespace Response {
class StepResponseImpl: public StepResponse {};
StepResponsePtr MakeStepResponseImpl();
} // Response
