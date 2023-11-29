#-------------------
# Module source
#-------------------

find_package(GTest REQUIRED)

# EXEC
add_executable(isPolindrom ./isPolindrom.cpp)

set(RUN_LEET_CODE_TEST runLeetcodeTest)
add_executable( ${RUN_LEET_CODE_TEST}
  runLeetcodeTest.cpp
  twoSums.cpp
)
target_include_directories(${RUN_LEET_CODE_TEST}
   ${GTEST_INCLUDE_DIRS} PUBLIC
)
target_link_libraries(${RUN_LEET_CODE_TEST}
    ${GTEST_LIBRARIES}
  )

set(NAMES
isPolindrom
${RUN_LEET_CODE_TEST}
)

install(TARGETS ${NAMES} DESTINATION bin)
