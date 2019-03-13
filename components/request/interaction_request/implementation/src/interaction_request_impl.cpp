#include "interaction_request_impl.hpp"

namespace Request {

InteractionRequestPtr MakeInteractionRequestImpl(){
    return std::make_shared<InteractionRequestImpl>();
}
} // Request