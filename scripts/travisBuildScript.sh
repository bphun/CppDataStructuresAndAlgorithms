#!/bin/bash
rootDir=$PWD
CHANGED_FILES=$(git diff --name-only $TRAVIS_COMMIT_RANGE)
echo $CHANGED_FILES

for file in $CHANGED_FILES; do
    dir=$(dirname $file)
    echo $dir

    cd $dir

    if [ -f "$CMakeLists.txt" ]; then    
        cd $rootDir
        ./scripts/buildProjectAtDir.sh $dir;
    elif [ -f "../CMakeLists.txt" ]; then    
        cd $rootDir
        ./scripts/buildProjectAtDir.sh $dir;
    fi
done

