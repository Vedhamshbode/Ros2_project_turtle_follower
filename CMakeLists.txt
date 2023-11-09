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

add_executable(Sub1 src/t_follower.cpp) 
ament_target_dependencies(Sub1 rclcpp turtlesim geometry_msgs)

install(TARGETS
  Sub1
  DESTINATION lib/${PROJECT_NAME}
)
install(TARGETS
  DESTINATION
  share/${PROJECT_NAME}/
)
ament_package()
