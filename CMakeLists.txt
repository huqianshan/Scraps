cmake_minimum_required(VERSION 3.0.0)
project(Scraps VERSION 0.1.0)
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_C_FLAGS_DEBUG "$ENV{CFLAGS} -O0 -Wall -g2 -ggdb3 -march=native -fsanitize=leak,address,undefined")
SET(CMAKE_C_FLAGS_RELEASE "$ENV{CFLAGS} -O3 -Ofast  -march=native -Wall")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CFLAGS} -O0 -Werror -Wreturn-type -g2 -ggdb3 -std=c++17 -fsanitize=leak,address,undefined -Wfatal-errors -Wno-deprecated -ftemplate-depth-128")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CFLAGS} -O3 -Ofast -Wall -march=native")

set (EXTRA_LIBS ${EXTRA_LIBS} pmem )#pthread )#pmem pmemobj pmemcto)
file(GLOB_RECURSE tests RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/C/*/*.c")
foreach(mainfile IN LISTS tests)
    # Get file name without directory
    get_filename_component(mainname ${mainfile} NAME_WE)
    SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) 
    add_executable(${mainname} ${mainfile})
    target_link_libraries(${mainname} ${EXTRA_LIBS})
endforeach()


set (EXTRA_LIBS ${EXTRA_LIBS})
file(GLOB_RECURSE tests RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/C++/*/*.cpp")
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
