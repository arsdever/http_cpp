# https://eb2.co/blog/2015/06/driving-boost.test-with-cmake/
# Copyright © 2017 Eric Scott Barr

function (create_boost_test)
    set (ONE_VALUE_ARGS MODULE_NAME)
    set (MULTI_VALUE_ARGS SOURCES)

    cmake_parse_arguments (
        CREATE_BOOST_TEST
        "${options}"
        "${ONE_VALUE_ARGS}"
        "${MULTI_VALUE_ARGS}"
        ${ARGN}
    )
    add_executable (${CREATE_BOOST_TEST_MODULE_NAME} ${CREATE_BOOST_TEST_SOURCES})

    foreach (SOURCE ${CREATE_BOOST_TEST_SOURCES})
		file(READ "${SOURCE}" SOURCE_FILE_CONTENTS)
        if ("${SOURCE_FILE_CONTENTS}" STREQUAL "")
            continue ()
        endif ()

		string(REGEX MATCHALL "(BOOST_AUTO_TEST_SUITE|BOOST_AUTO_TEST_CASE)\\( *([A-Za-z_0-9]+) *\\)" 
			   FOUND_TESTS ${SOURCE_FILE_CONTENTS})
        set (SUITE_NAME "")

		foreach(HIT ${FOUND_TESTS})
			string (REGEX REPLACE ".*\\( *([A-Za-z_0-9]+) *\\).*" "\\1" NAME ${HIT})
            # check if this is a suite name
            string (REGEX MATCH "BOOST_AUTO_TEST_SUITE" FOUND_MATCH ${HIT})
            if (NOT ${FOUND_MATCH} STREQUAL "")
                set (SUITE_NAME "${NAME}")
                continue ()
            endif ()

            if (${SUITE_NAME} STREQUAL "")
				add_test(NAME "${CREATE_BOOST_TEST_MODULE_NAME}/${NAME}" 
						 COMMAND ${CREATE_BOOST_TEST_MODULE_NAME}
						 --run_test=${TEST_NAME})
            else () 
				add_test(NAME "${CREATE_BOOST_TEST_MODULE_NAME}/${SUITE_NAME}/${NAME}" 
						 COMMAND ${CREATE_BOOST_TEST_MODULE_NAME}
						 --run_test=${SUITE_NAME}/${TEST_NAME})
            endif () 
		endforeach ()
	endforeach ()
endfunction ()
