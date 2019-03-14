message(STATUS "game_master")
project(GameMaster)

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::interface ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
        INTERFACE "${CMAKE_CURRENT_LIST_DIR}/interface")

add_subdirectory(implementation)
target_link_libraries(${PROJECT_NAME}
            INTERFACE   Player::interface
                        ActionRequest::interface
                        InteractionRequest::interface
                        StepRequest::interface
                        ActionResponse::interface
                        InteractionResponse::interface
                        StepResponse::interface)
