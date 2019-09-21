#!/bin/bash

./scripts/traverseAllSourceDirectories.sh ./scripts/buildProjectAtDir.sh $1

# for i in src/*/*
# do
#   ./scripts/buildProjectAtDir.sh $i &
# done

# for i in DataStructures/*
# do
#   if [ "$i" == "DataStructures/Tree" ]; then
#     for d in $i/*
#     do
#       ./scripts/buildProjectAtDir.sh $d &
#     done
#     continue
#   fi
#   ./scripts/buildProjectAtDir.sh $i &
# done

# wait
