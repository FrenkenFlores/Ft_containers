#!/bin/bash
CC=clang++
SRCS=test_map.cpp
NAME=test_map
$CC $SRCS -g -o $NAME
if [[ "$1" == "lldb" ]] ; then
    lldb test_map
    rm -rf test_map.dSYM
    rm test_map
    exit
fi
if [[ "$1" == "leaks" ]] ; then
    leaks -atExit -- ./test_map
    rm -rf test_map.dSYM
    rm test_map
    exit
fi
./test_map
rm test_map