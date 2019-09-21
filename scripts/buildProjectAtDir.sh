#!/bin/bash

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
