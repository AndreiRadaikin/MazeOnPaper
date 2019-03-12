message(STATUS "game_master")
project(GameMaster)

include(${CmakeHelpers}/default_component_structure.cmake)
target_link_libraries(${PROJECT_NAME}
            INTERFACE   Player::interface
                        Direction::interface
                        ActionRequest::interface
                        InteractionRequest::interface
                        ActionResponse::interface
                        InteractionResponse::interface
                        StepResponse::interface)
