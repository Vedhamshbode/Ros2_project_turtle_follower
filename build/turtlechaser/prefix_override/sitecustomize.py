import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/vedh/workspaces/Ros2_project_turtle_follower/install/turtlechaser'
