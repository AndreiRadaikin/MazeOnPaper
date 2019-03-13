message(STATUS "step_request")
project(StepRequest)

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::interface ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
        INTERFACE "${CMAKE_CURRENT_LIST_DIR}/interface")

add_subdirectory(implementation)
