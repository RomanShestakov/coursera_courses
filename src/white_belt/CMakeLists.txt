#-------------------
# Module source
#-------------------

find_package(GTest REQUIRED)

# EXEC
add_executable(assignment1 ./week1/01/assignment1.cpp)
add_executable(assignment2 ./week1/02/assignment2.cpp)
add_executable(assignment3 ./week1/03/assignment3.cpp)
add_executable(assignment4 ./week1/04/assignment.cpp)
add_executable(assignment5 ./week1/05/assignment.cpp)
add_executable(assignment6 ./week1/06/assignment.cpp)
add_executable(assignment7 ./week1/07/assignment.cpp)

set(RUN_WB_CODE_TEST runWBTest)
add_executable( ${RUN_WB_CODE_TEST}
  ../runGTest.cpp
  ./week2/wb_week2_tasks.cpp
)
target_include_directories(${RUN_WB_CODE_TEST}
   ${GTEST_INCLUDE_DIRS} PUBLIC
)
target_link_libraries(${RUN_WB_CODE_TEST}
    ${GTEST_LIBRARIES}
)

set(NAMES
assignment1
assignment2
assignment3
assignment4
assignment5
assignment6
assignment7
${RUN_WB_CODE_TEST}
)

install(TARGETS ${NAMES} DESTINATION bin)
