#-------------------
# Module source
#-------------------


# EXEC
add_executable(assignment1 ./week1/01/assignment1.cpp)
add_executable(assignment2 ./week1/02/assignment2.cpp)
add_executable(assignment3 ./week1/03/assignment3.cpp)
add_executable(assignment4 ./week1/04/assignment.cpp)
add_executable(assignment5 ./week1/05/assignment.cpp)

set(NAMES
assignment1
assignment2
assignment3
assignment4
assignment5
)

install(TARGETS ${NAMES} DESTINATION bin)
