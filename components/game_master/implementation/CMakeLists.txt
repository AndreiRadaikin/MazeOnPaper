message(STATUS "implementation")
project(GameMasterImpl)

add_library(${PROJECT_NAME} STATIC)
add_library(${INTERFACE_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_sources(${PROJECT_NAME}
               PRIVATE  "${CMAKE_CURRENT_LIST_DIR}/src/game_master_impl.cpp"
                        "${CMAKE_CURRENT_LIST_DIR}/src/player_info.cpp"
                        "${CMAKE_CURRENT_LIST_DIR}/src/maze.cpp"
                        "${CMAKE_CURRENT_LIST_DIR}/src/recurcive_maze_generator.cpp")

target_include_directories(${PROJECT_NAME}
               PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include")

target_link_libraries(${PROJECT_NAME} PUBLIC GameMaster::interface
                    Player::PlayerImpl
                    ActionRequest::ActionRequestImpl
                    InteractionRequest::InteractionRequestImpl
                    StepRequest::StepRequestImpl
                    ActionResponse::ActionResponseImpl
                    InteractionResponse::InteractionResponseImpl
                    StepResponse::StepResponseImpl
                    Point::Point)

add_subdirectory(test)
