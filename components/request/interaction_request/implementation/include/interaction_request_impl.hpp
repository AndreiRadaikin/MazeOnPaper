#pragma once

#include "interaction_request.hpp"

namespace Request {
class InteractionRequestImpl: public InteractionRequest {};
InteractionRequestPtr MakeInteractionRequestImpl();
} // Request
