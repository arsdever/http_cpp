cmake_minimum_required (VERSION 3.8)

file(GLOB_RECURSE HEADERS ${CMAKE_SOURCE_DIR}/include/*.h)

enable_testing()

add_executable(test "testmain.cpp" "response.cpp" "request.cpp" ${HEADERS} "http_server.cpp")
find_package (Boost COMPONENTS unit_test_framework)
target_include_directories(test PRIVATE ${BOOST_INCLUDE_DIRS})

add_test(NAME test COMMAND test)

target_link_libraries(test ${Boost_LIBRARIES})
target_include_directories(test PUBLIC ${CMAKE_SOURCE_DIR}/include ${Boost_INCLUDE_DIR})
target_precompile_headers(test PUBLIC ${CMAKE_SOURCE_DIR}/include/http/stdafx.h)