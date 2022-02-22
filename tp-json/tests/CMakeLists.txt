file(GLOB TESTS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} [0-9]*.cpp)

SET(OLDVAR 0)
SET(VAR 1)
FOREACH(TEST ${TESTS})
  MESSAGE(STATUS test:${TEST})
  add_executable(tp-json-test-${TEST} EXCLUDE_FROM_ALL ${TP-JSON-SOURCES} "${CMAKE_CURRENT_SOURCE_DIR}/${TEST}" )

  add_test(NAME build:${TEST} COMMAND "${CMAKE_COMMAND}" --build ${CMAKE_BINARY_DIR} --target tp-json-test-${TEST})
  set_tests_properties(build:${TEST} PROPERTIES FIXTURES_SETUP ${VAR})
  IF(NOT VAR EQUAL 1)
    set_tests_properties(build:${TEST} PROPERTIES FIXTURES_REQUIRED ${OLDVAR})
  ENDIF()

  SET(OLDVAR ${VAR})
  MATH(EXPR VAR "${VAR}+1")

  add_test(NAME run:${TEST} COMMAND ./tp-json-test-${TEST} "${CMAKE_CURRENT_SOURCE_DIR}/json/")
  set_tests_properties(run:${TEST} PROPERTIES FIXTURES_SETUP ${VAR})
  set_tests_properties(run:${TEST} PROPERTIES FIXTURES_REQUIRED ${OLDVAR})
   
  SET(OLDVAR ${VAR})
  MATH(EXPR VAR "${VAR}+1")
ENDFOREACH()
