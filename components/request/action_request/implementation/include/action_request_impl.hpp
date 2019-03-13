#pragma once

#include "action_request.hpp"

namespace Request {
class ActionRequestImpl: public ActionRequest {};
ActionRequestPtr MakeActionRequestImpl();
} // Request
