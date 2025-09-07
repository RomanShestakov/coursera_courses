#-------------------
# Module source
#-------------------

find_package(GTest REQUIRED)
find_package(rapidcheck REQUIRED)

# EXEC
add_executable(max1 ./basics/max.cpp)
add_executable(stack1 ./basics/stack1.cpp)

# set(LIB_ARRAYS_PROBLEMS array_problems)
# add_library( ${LIB_ARRAYS_PROBLEMS} SHARED
#   stringAndarray.cpp
# )

# set(LIB_LINKED_LIST_PROBLEMS linked_list_problems)
# add_library( ${LIB_LINKED_LIST_PROBLEMS} SHARED
#   linkedListsProblems.cpp
# )

# set(LIB_STACK_PROBLEMS stack_problems)
# add_library( ${LIB_STACK_PROBLEMS} SHARED
#   stackProblems.cpp
# )

# set(RUN_LEET_CODE_TEST runLeetcodeTest)
# add_executable( ${RUN_LEET_CODE_TEST}
#   ../runGTest.cpp
#   stringAndarrayTests.cpp
#   linkedListsTests.cpp
#   stackProblemsTests.cpp
# )
# target_include_directories(${RUN_LEET_CODE_TEST}
#    ${GTEST_INCLUDE_DIRS} PUBLIC
# )
# target_link_libraries(${RUN_LEET_CODE_TEST}
#    ${LIB_ARRAYS_PROBLEMS}
#    ${LIB_LINKED_LIST_PROBLEMS}
#    ${LIB_STACK_PROBLEMS}
#    ${GTEST_LIBRARIES}
#   )


# set(RUN_RC_TEST runRCTest)
# add_executable( ${RUN_RC_TEST}
#   rc_example.cpp
# )
# target_include_directories(${RUN_RC_TEST}
#    ${GTEST_INCLUDE_DIRS} PUBLIC
#    # ${rapidcheck_INCLUDE_DIRS} PUBLIC
#    rapidcheck PUBLIC
# )
# target_link_libraries(${RUN_RC_TEST}
#     ${GTEST_LIBRARIES}
#     rapidcheck
#   )

set(EXEC_NAMES
  max1
  stack1
# fizzbuz
# largestSum
# linkedList
# ${RUN_LEET_CODE_TEST}
)

# set(LIB_NAMES
# ${LIB_ARRAYS_PROBLEMS}
# ${LIB_LINKED_LIST_PROBLEMS}
# ${LIB_STACK_PROBLEMS}
# )

install(TARGETS ${EXEC_NAMES} DESTINATION bin)
#install(TARGETS ${LIB_NAMES} DESTINATION lib)
