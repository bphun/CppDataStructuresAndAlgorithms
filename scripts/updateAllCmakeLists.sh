#!/bin/bash

copyCMakeLists () {
  cp $PWD/MasterCMakeLists/CMakeLists.txt.in $currDirectory
  cp $PWD/MasterCMakeLists/CMakeLists.txt $currDirectory
}

export -f copyCMakeLists

./scripts/traverseAllSourceDirectories.sh copyCMakeLists

unset -f copyCMakeLists

# for i in src/*/*
# do
#   currDir=$i
#   copyCMakeLists
# done

# for i in DataStructures/*
# do
#   if [ "$i" == "DataStructures/Tree" ]; then
#     for d in $i/*
#     do
#       currDir=$d
#       copyCMakeLists
#     done
#     continue
#   fi
#   currDir=$i
#   copyCMakeLists
# done