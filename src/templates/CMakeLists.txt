#-------------------
# Module source
#-------------------

find_package(GTest REQUIRED)
find_package(rapidcheck REQUIRED)

# EXEC
add_executable(max1 ./basics/max.cpp)
add_executable(stack1 ./basics/stack1.cpp)
add_executable(binary ./basics/binary.cpp)


set(EXEC_NAMES
  max1
  stack1
  binary
)

install(TARGETS ${EXEC_NAMES} DESTINATION bin)
