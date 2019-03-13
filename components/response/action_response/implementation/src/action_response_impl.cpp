#include "action_response_impl.hpp"

namespace Response {

ActionResponsePtr MakeActionResponseImpl(){
    return std::make_shared<ActionResponseImpl>();
}
} // Response