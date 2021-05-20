#!/bin/bash
CC=clang++
SRCS=test_vector.cpp
NAME=test_vector
$CC $SRCS -g -o $NAME
if [[ "$1" == "lldb" ]] ; then
    lldb test_vector
    rm -rf test_vector.dSYM
    rm test_vector
    exit
fi
if [[ "$1" == "leaks" ]] ; then
    leaks -atExit -- ./test_vector
    rm -rf test_vector.dSYM
    rm test_vector
    exit
fi
./test_vector
rm test_vector