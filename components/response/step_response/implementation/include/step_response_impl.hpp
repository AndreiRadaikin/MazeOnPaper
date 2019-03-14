#pragma once

#include "step_response.hpp"
#include "step_result.hpp"
#include "field_type.hpp"

namespace Response {
class StepResponseImpl: public StepResponse {
public:
    StepResponseImpl(StepResult::Result result, FieldType::Type type);

private:
    const StepResult::Result result_;
    const FieldType::Type type_;
    StepResponseImpl();
};
StepResponsePtr MakeStepResponseImpl(StepResult::Result result, FieldType::Type type);
} // Response
