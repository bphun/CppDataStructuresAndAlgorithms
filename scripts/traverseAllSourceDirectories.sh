#!/bin/bash

action=$1
homeDirectory=$PWD
currDirectory=''

if [[ -z $action ]]; then
    echo "No action specified"
    exit 0
fi

if [ "$2" == "-p" ] || [ "$2" == "--parallel" ]; then
    parallelExec=true
    numCpuThreads=`grep -c ^processor /proc/cpuinfo`
fi

runAction () {
    if [ "$parallelExec" = true ]; then
        $action $currDirectory &
    else
        $action $currDirectory
    fi
}

for i in src/*/*
do
    currDirectory=$i
    runAction
done

for i in DataStructures/*
do
  if [ "$i" == "DataStructures/Tree" ]; then
    for d in $i/*
    do
        currDirectory=$d
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
