#-------------------
# Module source
#-------------------

find_package(GTest REQUIRED)
find_package(rapidcheck REQUIRED)

# EXEC
add_executable(isPolindrom ./isPolindrom.cpp)
add_executable(fizzbuz ./fizzbuz.cpp)
add_executable(largestSum ./main.cpp)

set(RUN_LEET_CODE_TEST runLeetcodeTest)
add_executable( ${RUN_LEET_CODE_TEST}
  runLeetcodeTest.cpp
  leetCodeTasks1.cpp
)
target_include_directories(${RUN_LEET_CODE_TEST}
   ${GTEST_INCLUDE_DIRS} PUBLIC
)
target_link_libraries(${RUN_LEET_CODE_TEST}
    ${GTEST_LIBRARIES}
  )


set(RUN_RC_TEST runRCTest)
add_executable( ${RUN_RC_TEST}
  rc_example.cpp
)
target_include_directories(${RUN_RC_TEST}
   ${GTEST_INCLUDE_DIRS} PUBLIC
   # ${rapidcheck_INCLUDE_DIRS} PUBLIC
   rapidcheck PUBLIC
)
target_link_libraries(${RUN_RC_TEST}
    ${GTEST_LIBRARIES}
    rapidcheck
  )

set(NAMES
isPolindrom
fizzbuz
largestSum
${RUN_LEET_CODE_TEST}
)

install(TARGETS ${NAMES} DESTINATION bin)
