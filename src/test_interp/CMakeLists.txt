cmake_minimum_required(VERSION 2.8.3)
project(test_interp)

find_package(catkin REQUIRED COMPONENTS roscpp)

find_package(interpolation REQUIRED)

catkin_package(
  CATKIN_DEPENDS roscpp 
  DEPENDS interpolation
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${interpolation_INCLUDE_DIRS}
)

add_executable(test_interp src/test.cpp)

target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
  interpolation
)









