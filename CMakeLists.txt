cmake_minimum_required(VERSION 3.14)
project(Quanty VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(quant_engine src/Option.cpp src/BlackScholesPricer.cpp)

target_include_directories(quant_engine PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include> )

add_executable(quanty src/main.cpp)
target_link_libraries(quanty PRIVATE quant_engine)


# --- Unit Testing Configuration ---
enable_testing()

# Create a test executable target
add_executable(unit_tests tests/test_quant.cpp)

# Link it to your quant engine library so it has access to headers and core logic
target_link_libraries(unit_tests PRIVATE quant_engine)

# Register the executable as a test case with CTest
add_test(NAME QuantEngineUnitTests COMMAND unit_tests)

