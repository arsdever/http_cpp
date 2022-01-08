find_package (Boost COMPONENTS unit_test_framework)

include (BoostTestHelpers)

create_boost_test(MODULE_NAME http_test SOURCES "testmain.cpp" "response.cpp" "request.cpp" "http_server.cpp")
target_link_libraries(http_test PUBLIC ${Boost_LIBRARIES})
target_include_directories(http_test PUBLIC ${CMAKE_SOURCE_DIR}/include ${Boost_INCLUDE_DIRS})
target_precompile_headers(http_test PUBLIC ${CMAKE_SOURCE_DIR}/include/http/stdafx.h)