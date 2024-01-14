#-------------------
# Module source
#-------------------

find_package(GTest REQUIRED)

# EXEC
# add_executable(isPolindrom ./isPolindrom.cpp)
# add_executable(fizzbuz ./fizzbuz.cpp)
# add_executable(largestSum ./main.cpp)
# add_executable(linkedList ./linkedListExample.cpp)

set(LIB_COOKBOOK cookbook)
add_library( ${LIB_COOKBOOK} SHARED
  cookbook_01.cpp
)

set(RUN_COOKBOOK_TEST runcookbokTest)
add_executable( ${RUN_COOKBOOK_TEST}
  ../runGTest.cpp
  test01.cpp
)
target_include_directories(${RUN_COOKBOOK_TEST}
   ${GTEST_INCLUDE_DIRS} PUBLIC
)
target_link_libraries(${RUN_COOKBOOK_TEST}
   ${LIB_COOKBOOK}
   ${GTEST_LIBRARIES}
  )

set(EXEC_NAMES
# isPolindrom
# fizzbuz
# largestSum
# linkedList
${RUN_COOKBOOK_TEST}
)

set(LIB_NAMES
${LIB_COOKBOOK}
)

install(TARGETS ${EXEC_NAMES} DESTINATION bin)
install(TARGETS ${LIB_NAMES} DESTINATION lib)
