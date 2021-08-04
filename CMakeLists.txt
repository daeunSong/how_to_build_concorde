cmake_minimum_required(VERSION 3.10)

project(concordeTest)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)

set(PROJECT_DIR ${PROJECT_SOURCE_DIR})

include_directories(
  ${PROJECT_DIR}/lib/concorde
  ${PROJECT_DIR}/lib/qsopt
)

add_executable(${PROJECT_NAME} ${PROJECT_DIR}/src/main.cpp)

target_link_libraries(${PROJECT_NAME} 
  ${PROJECT_DIR}/lib/concorde/concorde.a
  ${PROJECT_DIR}/lib/qsopt/qsopt.a
)
