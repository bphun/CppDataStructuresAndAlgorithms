#!/bin/bash

# Builds a project at a user specified directory. Specify the path to the directoy in $1

projectDir=$1
homeDir=$PWD

cd $projectDir

if [ ! -d "build" ]; then
    mkdir build
fi

cd build
echo $PWD

cmake ../ && make

cd $homeDir
