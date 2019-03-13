#pragma once

#include "action_response.hpp"

namespace Response {
class ActionResponseImpl: public ActionResponse {};
ActionResponsePtr MakeActionResponseImpl();
} // Response
