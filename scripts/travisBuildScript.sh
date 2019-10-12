#!/bin/bash

CHANGED_FILES=$(git diff --name-only $TRAVIS_COMMIT_RANGE)
echo $CHANGED_FILES
for file in $CHANGED_FILES; do
    dir=$(dirname $file);
    echo $dir;
done

if [ -f "$dir/CMakeLists.txt" ]; then    
    ./scripts/buildProjectAtDir.sh $dir;
elif [ -f "$dir/../CMakeLists.txt" ]; then    
    ./scripts/buildProjectAtDir.sh $dir;
fi

