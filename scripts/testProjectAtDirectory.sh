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

if [[ "$?" -eq "1" ]]; then
    exit 1
fi

cd $homeDir