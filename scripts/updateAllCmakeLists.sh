#!/bin/bash

# Updates the CMakeLists.txt.in and CMakeLists.txt files found in each dataStructures/ and algorithms/
# directory with respective versions found in masterCMakeLists/

copyCMakeLists () {
    cp $PWD/masterCMakeLists/CMakeLists.txt.in $currDirectory
    cp $PWD/masterCMakeLists/CMakeLists.txt $currDirectory
}

export -f copyCMakeLists

./scripts/traverseAllSourceDirectories.sh copyCMakeLists

unset -f copyCMakeLists