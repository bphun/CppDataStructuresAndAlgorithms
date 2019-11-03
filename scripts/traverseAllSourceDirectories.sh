#!/bin/bash

# cd's into every directory found in dataStructures/ and algorithms/ and runs a command.
# This command can be specified by providing its name in the command line arguments

action=$1
homeDirectory=$PWD
currDirectory=''
kernel=`uname`

if [ "$2" == "-p" ] || [ "$2" == "--parallel" ]; then
    parallelExec=true
    if [ "$kernel" == "linux" ]; then
        numCpuThreads=`grep -c ^processor /proc/cpuinfo`
    elif [ "$kernel" == "darwin" ]; then
        numCpuThreads=`sysctl -n hw.ncpu`
    fi
fi

runAction () {
    if [ "$parallelExec" = true ]; then
        $action $currDirectory &
    else
        $action $currDirectory
    fi

    if [[ "$?" -eq "1" ]]; then
        exit 1
    fi
}

for i in algorithms/*/*
do
    if [ "$i" == "algorithms/util/SortingUtil.h" ]; then
        continue
    fi

    currDirectory=$i
    runAction
done

for i in dataStructures/*
do
    if [ "$i" == "dataStructures/Tree" ]; then
        for d in $i/*
        do
            currDirectory=$i$d
            runAction
        done
        continue
    fi

    currDirectory=$i
    runAction

done

if [ "$parallelExec" = true ]; then
    wait
fi
