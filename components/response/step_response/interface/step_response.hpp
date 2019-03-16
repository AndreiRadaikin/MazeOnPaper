#pragma once

#include <memory>
#include "step_result.hpp"

namespace Response {
class StepResponse {
public:
    virtual ~StepResponse() {}
    virtual StepResult::Result GetResult() const = 0;
};
typedef std::shared_ptr<StepResponse> StepResponsePtr;
} // Response
