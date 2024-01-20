#-------------------
# Module source
#-------------------

find_package(GTest REQUIRED)

# EXEC
add_executable(divmod ./01/divmod.c)
add_executable(fib ./1.3/fib.c)
add_executable(mem_allocation ./2.1/mem_allocation.c)

set(RUN_C_LECTURES_CODE_TEST runCTest)
add_executable( ${RUN_C_LECTURES_CODE_TEST}
  ../runGTest.cpp
  ./01/gcd.c
  clecturesTests.cpp
)
target_include_directories(${RUN_C_LECTURES_CODE_TEST}
   ${GTEST_INCLUDE_DIRS} PUBLIC
)
target_link_libraries(${RUN_C_LECTURES_CODE_TEST}
    ${GTEST_LIBRARIES}
  )

set(NAMES
divmod
fib
mem_allocation
${RUN_C_LECTURES_CODE_TEST}
)

install(TARGETS ${NAMES} DESTINATION bin)
