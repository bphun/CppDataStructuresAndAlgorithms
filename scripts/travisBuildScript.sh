#!/bin/bash
rootDir=$PWD
CHANGED_FILES=$(git diff --name-only $TRAVIS_COMMIT_RANGE)
echo "Changed Files: $CHANGED_FILES"

for file in $CHANGED_FILES; do
    dir=$(dirname $file)

    cd $dir

    echo $dir

    if [ -f "$CMakeLists.txt" ]; then    
        cd $rootDir
        echo "Building project at $dir"
        ./scripts/buildProjectAtDir.sh $dir;
    elif [ -f "../CMakeLists.txt" ]; then    
        cd $rootDir
        echo "Building project at $dir/g../"
        ./scripts/buildProjectAtDir.sh $dir/../;
    fi
done

