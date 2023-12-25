#-------------------
# Module source
#-------------------

# EXEC
#add_executable(isPolindrom ./isPolindrom.cpp)

set(NAMES
# isPolindrom
# fizzbuz
# largestSum
# linkedList
# ${RUN_LEET_CODE_TEST}
)

install(TARGETS ${NAMES} DESTINATION bin)
