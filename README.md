## Arena Camera Driver for ROS1

# Getting Started
setup and usage https://support.thinklucid.com/using-ros-for-linux/


for ROS2 driver contact LUCID support for more information 
https://support.thinklucid.com/contact-support/

# Achieve reliable image streams Linux
Be sure to set the packet size of your ethernet connection to a sufficient size.  
`ip link set ethx mtu 9000`  
Be sure to set your receiving buffer size sufficiently large. Requires ethtool.  
`sudo ethtool -G ethx rx 4096`  

# Configure and launch the camera stream
A config and launch file for the LUCID TDR054S-CC are added under the `catkin_ws/src/arena_camera` folder. A first camera calibration file has been added as well. Calibrated using [camera_calibration](http://wiki.ros.org/camera_calibration) for a [Kowa LM6JC lens](https://www.kowa-lenses.com/en/lm6jc-mp-industrial-lens-c-mount) set at aperture 4 and focal distance infinity.  
To set parameters that are not supported yet, you have to write some code yourself. Look at commit [604adc7](https://github.com/Intermodalics/arena_camera_ros/commit/604adc7b32506ace1518cb5a800fa39d78cf3e9e) as example.  
When doing so, make sure you get the setting names and datatypes right, it is advised to go to their on-device documentation.  
1. Open the camera’s IP in a browser and go for Documentation>Device Nodes. The node names are the same as we have to set in our code to grab and write settings.
2. Check the datatypes and view current settings of the camera by using the precompiled `Cpp_ExploreNodes` executable in `ArenaSDK_Linux_x64/precompiled_examples/`. There you can also see the Read/Writability/NotImplemented status of the parameters.

# After every launch of a docker container
After each launch of a docker container, be sure to call ```catkin build arena_camera --force-cmake``` to force sourcing of ArenaSDK. Otherwise launching any rosnode for LUCID won't work.
