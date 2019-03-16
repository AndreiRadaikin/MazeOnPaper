project(MazeOnPaper)

add_executable(${PROJECT_NAME})
add_executable(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

find_package(Qt5Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
qt5_wrap_cpp(QtMockPlayerUi  "${CMAKE_CURRENT_LIST_DIR}/include/player_ui.hpp")
qt5_wrap_cpp(QtMockMap       "${CMAKE_CURRENT_LIST_DIR}/include/map.hpp")


target_include_directories(${PROJECT_NAME}
                PRIVATE "${CMAKE_CURRENT_LIST_DIR}/include")
target_sources(${PROJECT_NAME}
                PRIVATE "${CMAKE_CURRENT_LIST_DIR}/main.cpp"
                        "${CMAKE_CURRENT_LIST_DIR}/src/player_ui.cpp"
                        "${CMAKE_CURRENT_LIST_DIR}/src/map.cpp"
                        ${QtMockPlayerUi}
                        ${QtMockMap})

target_link_libraries(${PROJECT_NAME}
                PRIVATE Qt5::Widgets
                        Point::Point
                        Player::interface
                        GameMaster::GameMasterImpl
                        StepRequest::StepRequestImpl
                        StepResponse::StepResponseImpl)

install(TARGETS ${PROJECT_NAME}
DESTINATION ${BINARY_DIR})
