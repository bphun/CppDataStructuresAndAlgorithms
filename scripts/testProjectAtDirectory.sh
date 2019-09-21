#!/bin/bash

projectDir=$1
homeDir=$PWD

cd $projectDir

if [ ! -d "build" ]; then
    echo "Build directory not found, exiting"
    exit 0
fi

cd build/

# make test

testName=`echo $PWD | rev | cut -d '/' -f2 | rev`Test

./$testName

cd $homeDir