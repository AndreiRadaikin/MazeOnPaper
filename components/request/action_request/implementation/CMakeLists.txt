message(STATUS "implementation")

project(ActionRequestImpl)

add_library(${PROJECT_NAME} STATIC)
add_library(ActionRequest::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_sources(${PROJECT_NAME}
               PRIVATE "${CMAKE_CURRENT_LIST_DIR}/src/action_request_impl.cpp")

target_include_directories(${PROJECT_NAME}
               PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include")

target_link_libraries(${PROJECT_NAME} PRIVATE ActionRequest::interface)
