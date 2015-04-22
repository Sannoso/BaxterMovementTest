# Baxter

This repository contains scripts to support the [Baxter Research Robot](http://www.rethinkrobotics.com/baxter-research-robot/).
The scripts are based on information provided on the [Baxter Research Robot Wiki](http://sdk.rethinkrobotics.com/wiki/Main_Page).

More specific:
This repository contains scripts to test different movement algorithms on the Baxter robot.
The scripts create .csv files as output to be analysed further in for example microsoft Excel

## Installation

NOTE: To run these scripts with the Baxter repository you must have acces to the following private repository: https://github.com/RethinkRobotics/baxter_simulator
Follow the instructions in https://github.com/dortmans/baxter/blob/master/README.md
of the https://github.com/dortmans/baxter    repository.

After that has been done clone this repository:

    cd ~
    git clone https://github.com/Sannoso/BaxterMovementTest

Then make the scripts executable:

    cd ~/BaxterMovementTest
    chmod +x *.bash

## Using the scripts

Start the simulator in a terminal:
    cd ~/baxter
    ./start_simulator.bash
wait for the terminal to say [ INFO] [<timestamp walltime>, <timestamp2>]: Gravity compensation was turned off
this can take a minut or two. You should only proceed after that output

Then open a new terminal and start the setup script with an additional `sim` argument:
    cd ~/baxter
    ./setup.bash sim
    rosrun baxter_tools enable_robot.py -e
it should return: [INFO] [WallTime: 1429532706.734450] [40.801000] Robot Enabled
    rosrun baxter_interface joint_trajectory_action_server.py

After that the scripts of this repo can be ran in a third terminal


##Dear reader,
English is not my native language if you see any spelling or grammar errors please point them out to me so I can correct them and improve my skills in English.
