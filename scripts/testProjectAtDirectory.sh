#!/bin/bash

# Builds and runs tests for a data structure or algorithm at a specified path. 
# Specify a path as a command line argument like so ./testProjectAtDirectory.sh <Path-To-Source>

projectDir=$1
homeDir=$PWD

cd $projectDir

if [ ! -d "build" ]; then
    echo "Build directory not found, exiting"
    exit 0
fi

cd build/

testName=`echo $PWD | rev | cut -d '/' -f2 | rev`Test

./$testName

if [[ "$?" -eq "1" ]]; then
    exit 1
fi

cd $homeDir