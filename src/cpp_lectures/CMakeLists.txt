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
add_executable(rvalue ./05/rvalue.cpp)
add_executable(method_annotation ./05/method_annotation.cpp)
add_executable(silly_pointer ./05/silly_pointer.cpp)
add_executable(static_and_friend ./06/static_and_friend.cpp)
add_executable(bit_cast ./06/bit_cast.cpp)
add_executable(static_cast ./06/static_cast.cpp)
add_executable(positive_hack ./06/positive_hack.cpp)
add_executable(operator_overload ./06/operator_overload.cpp)
add_executable(post_pre_increment ./06/post_pre_increment.cpp)
add_executable(strange_implicit_cast ./06/strange_implicit_cast.cpp)
add_executable(spaceship ./07/spaceship.cpp)
add_executable(addressof ./07/addressof.cpp)
add_executable(pointer_to_class_memeber ./07/pointer_to_class_memeber.cpp)
add_executable(inheritance ./08/inheritance.cpp)
add_executable(virtual_destructor ./08/virtual_destructor.cpp)
add_executable(deleter ./08/deleter.cpp)
add_executable(static_binding ./08/static_binding.cpp)

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
rvalue
method_annotation
silly_pointer
static_and_friend
bit_cast
static_cast
positive_hack
operator_overload
post_pre_increment
strange_implicit_cast
spaceship
addressof
pointer_to_class_memeber
inheritance
virtual_destructor
deleter
static_binding
#${RUN_CPP_LECTURES_CODE_TEST}
)

install(TARGETS ${NAMES} DESTINATION bin)
