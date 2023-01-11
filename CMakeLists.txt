cmake_minimum_required(VERSION 3.5)
project(patchworkpp)

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

add_compile_options(-Wall -Wextra -Wpedantic -Wshadow -Wuninitialized)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(PCL REQUIRED)
find_package(pcl_conversions REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(Eigen3 REQUIRED)

add_executable(lidar_filter src/patchworkpp.cpp)
target_link_libraries(lidar_filter ${PCL_LIBRARIES} ${EIGEN3_LIBRARIES})
ament_target_dependencies(lidar_filter rclcpp sensor_msgs pcl_conversions)
target_include_directories(lidar_filter
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

install(TARGETS
  lidar_filter
  DESTINATION lib/${PROJECT_NAME})

install(
  DIRECTORY config
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
