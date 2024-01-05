#-------------------
# Module source
#-------------------

find_package(GTest REQUIRED)

# EXEC
add_executable(newdelete ./03/newdelete.cpp)
add_executable(dangling_pointer ./03/dangling_pointer.cpp)
add_executable(dangling_reference ./03/dangling_reference.cpp)

# set(RUN_C_LECTURES_CODE_TEST runCTest)
# add_executable( ${RUN_C_LECTURES_CODE_TEST}
#   ../runGTest.cpp
#   ./01/gcd.c
#   clecturesTests.cpp
# )
# target_include_directories(${RUN_C_LECTURES_CODE_TEST}
#    ${GTEST_INCLUDE_DIRS} PUBLIC
# )
# target_link_libraries(${RUN_C_LECTURES_CODE_TEST}
#     ${GTEST_LIBRARIES}
#   )

set(NAMES
newdelete
dangling_pointer
dangling_reference
#${RUN_CPP_LECTURES_CODE_TEST}
)

install(TARGETS ${NAMES} DESTINATION bin)
