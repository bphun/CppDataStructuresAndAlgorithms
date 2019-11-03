#!/bin/bash

# Removes all build directories from every folder in dataStructures/ and algorithms/

cleanup () {
    cd $currDirectory
    rm -rf build
    cd $homeDirectory
}

export -f cleanup

./scripts/traverseAllSourceDirectories.sh cleanup

unset -f cleanup

cd RunAllTestHarnesses/
rm -rf build
cd ../