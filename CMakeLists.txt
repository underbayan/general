## 要求的最低cmake 版本
cmake_minimum_required(VERSION 3.4)
## 工程名称
project(general)
include(CTest)
set (GENERAL_VERSION_MAJOR 1)
set (GENERAL_VERSION_MINOR 0)
set (INCLUDE_TEMPLATE src/include_template)
set (LIB_DIR src/libs)
set (DIST_DIR Release)
set (DIST_DIR Debug)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DIST_DIR})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
configure_file (
        "${INCLUDE_TEMPLATE}/version.h.in"
        "${INCLUDE_TEMPLATE}/version.h"
)
option (USE_MYMATH  "Use tutorial provided math implementation" ON)
if (USE_MYMATH)
    include_directories ("${LIB_DIR}/MathFunctions")
    add_subdirectory ("${LIB_DIR}/MathFunctions")
    set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

set(SOURCE_FILES  src/basic.cpp  src/include_template/version.h.in )
add_executable("my_sqrt" src/mysqrt.cpp)
add_executable("flapjack" src/flapjack.cpp )
add_executable("test__"  src/test.cpp )
add_executable("AKS"  src/AKS.cpp )
add_executable("Concurrent"  src/Concurrent.cpp )
add_executable("Lock"  src/Lock.cpp )

target_link_libraries (my_sqrt  ${EXTRA_LIBS})
install (TARGETS my_sqrt DESTINATION bin)

macro (do_test arg result)
    add_test (my_sqrt_comp_${arg} my_sqrt ${arg})
    set_tests_properties (my_sqrt_comp_${arg} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

# TODO: how to enable the cout function in cmake test
#add_test (Concurrent-test Concurrent)

add_test (lock-test Lock)
