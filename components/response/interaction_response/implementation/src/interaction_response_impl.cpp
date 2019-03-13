#include "interaction_response_impl.hpp"

namespace Response {

InteractionResponsePtr MakeInteractionResponseImpl(){
    return std::make_shared<InteractionResponseImpl>();
}
} // Response