cmake_minimum_required(VERSION 3.0.0)
project(Scraps VERSION 0.1.0)

#set (EXTRA_LIBS ${EXTRA_LIBS} pthread)
file(GLOB_RECURSE tests RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/C/*/*.c")
foreach(mainfile IN LISTS tests)
    # Get file name without directory
    get_filename_component(mainname ${mainfile} NAME_WE)
    SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) 
    add_executable(${mainname} ${mainfile})
    target_link_libraries(${mainname} ${EXTRA_LIBS})
endforeach()

#add_executable(Scraps main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
