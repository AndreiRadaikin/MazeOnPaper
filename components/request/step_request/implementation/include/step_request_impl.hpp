#pragma once

#include "step_request.hpp"

namespace Request {
class StepRequestImpl: public StepRequest {
public:
    StepRequestImpl(size_t name, Direction::Direction direction);
    ~StepRequestImpl();
    size_t GetName() const override;
    Direction::Direction GetDirection() const override;
private:
    StepRequestImpl();
    const size_t name_;
    Direction::Direction direction_;
};
StepRequestConstPtr MakeStepRequestImpl(size_t name, Direction::Direction direction);
} // Request
