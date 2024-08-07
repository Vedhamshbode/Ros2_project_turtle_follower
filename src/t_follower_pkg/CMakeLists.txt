cmake_minimum_required(VERSION 3.8)
project(t_follower_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(turtlesim REQUIRED)
find_package(geometry_msgs REQUIRED)

add_executable(t_follower_sub src/t_follower.cpp) 
ament_target_dependencies(t_follower_sub rclcpp turtlesim geometry_msgs)

install(TARGETS
  t_follower_sub
  DESTINATION lib/${PROJECT_NAME}
)
install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)
ament_package()
