#include "step_request_impl.hpp"

namespace Request {


StepRequestConstPtr MakeStepRequestImpl(size_t name, Direction::Direction direction){
    return std::make_shared<const StepRequestImpl>(name, direction);
}

StepRequestImpl::StepRequestImpl(size_t name, Direction::Direction direction):name_(name), direction_(direction)
{

}

StepRequestImpl::~StepRequestImpl()
{

}

size_t StepRequestImpl::GetName() const
{
    return name_;
}

Direction::Direction StepRequestImpl::GetDirection() const
{
    return direction_;
}

} // Request
