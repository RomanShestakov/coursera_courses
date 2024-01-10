#-------------------
# Module source
#-------------------

find_package(GTest REQUIRED)

# EXEC
##add_executable(split ./week4/split.cpp)
#add_executable(assignment1 ./week1/01/assignment1.cpp)
# add_executable(assignment2 ./week1/02/assignment2.cpp)
# add_executable(assignment3 ./week1/03/assignment3.cpp)
# add_executable(assignment4 ./week1/04/assignment.cpp)
# add_executable(assignment5 ./week1/05/assignment.cpp)
# add_executable(assignment6 ./week1/06/assignment.cpp)
# add_executable(assignment7 ./week1/07/assignment.cpp)

set(LIB_RB red_belt)
add_library( ${LIB_RB} SHARED
  ./week4/stringView.cpp
)

set(RUN_RB_CODE_TEST runRBTest)
add_executable( ${RUN_RB_CODE_TEST}
  ../runGTest.cpp
  test.cpp
)
target_include_directories(${RUN_RB_CODE_TEST}
   ${GTEST_INCLUDE_DIRS} PUBLIC
)
target_link_libraries(${RUN_RB_CODE_TEST}
    ${GTEST_LIBRARIES}
    ${LIB_RB}
)

set(EXEC_NAMES
#assignment1
# assignment2
# assignment3
# assignment4
# assignment5
# assignment6
# assignment7
${RUN_RB_CODE_TEST}
)

set(LIB_NAMES
${LIB_RB}
)

install(TARGETS ${EXEC_NAMES} DESTINATION bin)
install(TARGETS ${LIB_NAMES} DESTINATION lib)
