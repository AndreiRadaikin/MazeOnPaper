#pragma once

#include "interaction_response.hpp"

namespace Response {
class InteractionResponseImpl: public InteractionResponse {};
InteractionResponsePtr MakeInteractionResponseImpl();
} // Response
