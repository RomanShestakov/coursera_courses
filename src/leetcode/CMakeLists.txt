#-------------------
# Module source
#-------------------


# EXEC
add_executable(isPolindrom ./isPolindrom.cpp)

set(NAMES
isPolindrom
)

install(TARGETS ${NAMES} DESTINATION bin)
