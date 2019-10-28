# Algorithms and Data Structures

[![Build Status](https://travis-ci.org/bphun/CppDataStructuresAndAlgorithms.svg?branch=master)](https://travis-ci.org/bphun/CppDataStructuresAndAlgorithms)

A collection of common algorithms and data structures implemented in C++ using the C++11 standard.

## Building Tests
To build a single data structure or algorithm, navigate to the directory of the data structure or algorithm you would like to test and run the following commands:
* `mkdir build`
* `cd build`
* `cmake ../`
* `make`

Once you do that, you can run either run `make test` or `./${FolderName}Test` if you would like a more comprehensive breakdown of each of the tests being run. For example, if you want to run tests for the LinkedList class, run `./LinkedListTest`.

To test all data structures and algorithms, navigate to the **RunAllTestHarnesses** directory and then run the following:
* `mkdir build`
* `cd build`
* `cmake ../`
* `make`
* `./RunAllTestHarnesses`
