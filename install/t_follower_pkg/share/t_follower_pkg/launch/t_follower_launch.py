from launch import LaunchDescription
from launch.actions import ExecuteProcess, LogInfo, RegisterEventHandler
from launch.event_handlers import OnProcessStart 
from launch.substitutions import FindExecutable, LaunchConfiguration
from launch_ros.actions import Node
from launch.conditions import IfCondition


def generate_launch_description():
    turtlesim_node = Node(
        package="turtlesim",
        executable="turtlesim_node",
        name="sim",
    )

    turtle_teleop_key_node = ExecuteProcess(
            cmd=['gnome-terminal', '--', 'ros2', 'run', 'turtlesim', 'turtle_teleop_key', '--ros-args -remap turtle:=turtle2'],
            output='screen'
        )

    t_follower_node = Node(
        package="t_follower_pkg",
        executable="t_follower_sub"
    )

    spawn_turtle = ExecuteProcess(
        cmd=[
            [
                FindExecutable(name="ros2"),
                " service call ",
                "/spawn ",
                "turtlesim/srv/Spawn ",
                "\"{x: 2.0, y: 2.0, theta: 0.0, name: 'turtle2'}\"",
            ]
        ],
        shell=True,
    )
    return LaunchDescription(
        [
            turtlesim_node,
            turtle_teleop_key_node,
            RegisterEventHandler(
                OnProcessStart(
                    target_action=turtlesim_node,
                    on_start=[
                        LogInfo(msg="Turtlesim started, spawning turtle"),
                        spawn_turtle,
                    ],
                )
            ),
            t_follower_node,
        ]
    )
