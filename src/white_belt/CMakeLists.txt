#-------------------
# Module source
#-------------------


# EXEC
add_executable(assignment1 ./week1/01/assignment1.cpp)
add_executable(assignment2 ./week1/02/assignment2.cpp)
add_executable(assignment3 ./week1/03/assignment3.cpp)

set(NAMES
assignment1
assignment2
assignment3

)

install(TARGETS ${NAMES} DESTINATION bin)
