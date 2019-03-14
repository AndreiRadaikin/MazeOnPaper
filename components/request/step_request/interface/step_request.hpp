#pragma once

#include <memory>
#include "direction.hpp"

namespace Request {
class StepRequest {
public:
    virtual ~StepRequest() {}
    virtual size_t GetName() const = 0;
    virtual Direction::Direction GetDirection() const = 0;
};

typedef std::shared_ptr<const StepRequest> StepRequestConstPtr;
} // Request
