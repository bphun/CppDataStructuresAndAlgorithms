#!/bin/bash

# currDirectory=''
# homedir=$PWD

cleanup () {
    cd $currDirectory
    rm -rf build
    cd $homeDirectory
}

export -f cleanup

./scripts/traverseAllSourceDirectories.sh cleanup

unset -f cleanup

# for i in src/*/*
# do
#   currDirectory=$i
#   cleanup
# done

# for i in DataStructures/*
# do
#   if [ "$i" == "DataStructures/Tree" ]; then
#     for d in $i/*
#     do
#       currDirectory=$d
#       cleanup
#     done
#     continue
#   fi
#   currDirectory=$i
#   cleanup
# done