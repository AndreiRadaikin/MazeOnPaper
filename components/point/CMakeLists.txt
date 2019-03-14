project(Point)

add_library(${PROJECT_NAME} STATIC)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_sources(${PROJECT_NAME}
               PRIVATE "${CMAKE_CURRENT_LIST_DIR}/src/point.cpp")

target_include_directories(${PROJECT_NAME}
               PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include")
