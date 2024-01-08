#-------------------
# Module source
#-------------------

find_package(GTest REQUIRED)

# EXEC
add_executable(newdelete ./03/newdelete.cpp)
add_executable(dangling_pointer ./03/dangling_pointer.cpp)
add_executable(dangling_reference ./03/dangling_reference.cpp)
add_executable(const_ref ./03/const_ref.cpp)
add_executable(pointer_to_array ./03/pointer_to_array.cpp)
add_executable(class_init ./04/class_init.cpp)
add_executable(cntr_delegation ./04/cntr_delegation.cpp)
add_executable(rvo ./04/rvo.cpp)
add_executable(cv ./04/cv.cpp)
add_executable(explicit_convertion ./04/explicit_convertion.cpp)

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
const_ref
pointer_to_array
class_init
cntr_delegation
rvo
cv
explicit_convertion
#${RUN_CPP_LECTURES_CODE_TEST}
)

install(TARGETS ${NAMES} DESTINATION bin)
