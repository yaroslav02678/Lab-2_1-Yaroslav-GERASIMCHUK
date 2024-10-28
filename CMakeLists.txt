cmake_minimum_required(VERSION 3.29)
project(Lab-2_4-IDE-project)
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/Library)

add_library(ProjectLib
    src/Library/SoftwareEngineeringStudent.cpp
    src/Library/ComputerEngineeringStudent.cpp
    src/Library/CyberSecurityStudent.cpp
    src/Library/Question.cpp
    src/Library/User.cpp
    src/Library/Admin.cpp
)

add_executable(Lab-2_4-IDE-project src/main.cpp)
target_link_libraries(Lab-2_4-IDE-project ProjectLib)
