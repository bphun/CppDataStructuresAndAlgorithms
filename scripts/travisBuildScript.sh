#!/bin/bash
currDir=$PWD
CHANGED_FILES=$(git diff --name-only $TRAVIS_COMMIT_RANGE)
echo $CHANGED_FILES

for file in $CHANGED_FILES; do
    dir=$(dirname $file)
    echo $dir

    cd $dir

    if [ -f "$CMakeLists.txt" ]; then    
        ./scripts/buildProjectAtDir.sh $dir;
    elif [ -f "../CMakeLists.txt" ]; then    
        ./scripts/buildProjectAtDir.sh $dir;
    fi

    cd $currDir
done

