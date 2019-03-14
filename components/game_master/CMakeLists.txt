message(STATUS "game_master")
project(GameMaster)

set(LIBRARIES   Player::interface
                ActionRequest::interface
                InteractionRequest::interface
                StepRequest::interface
                ActionResponse::interface
                InteractionResponse::interface
                StepResponse::interface)

MakeInterfaseStructure()

