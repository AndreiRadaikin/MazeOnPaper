function(MakeInterfaseStructure)
add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::interface ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
        INTERFACE "${CMAKE_CURRENT_LIST_DIR}/interface")

if(LIBRARIES)
 target_link_libraries(${PROJECT_NAME} INTERFACE ${LIBRARIES})
endif()

set(INTERFACE_NAME ${PROJECT_NAME})
add_subdirectory(implementation)
endfunction(MakeInterfaseStructure)

