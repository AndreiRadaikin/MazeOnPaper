#include "step_response_impl.hpp"

namespace Response {

StepResponsePtr MakeStepResponseImpl(StepResult::Result result, FieldType::Type type){
    return std::make_shared<StepResponseImpl>(result, type);
}

StepResponseImpl::StepResponseImpl(StepResult::Result result, FieldType::Type type):result_(result), type_(type)
{

}

} // Response
