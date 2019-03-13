#include "action_request_impl.hpp"

namespace Request {

ActionRequestPtr MakeActionRequestImpl(){
    return std::make_shared<ActionRequestImpl>();
}
} // Request