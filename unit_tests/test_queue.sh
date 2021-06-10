#!/bin/bash
CC=clang++
SRCS=test_queue.cpp
NAME=test_queue
$CC $SRCS -g -o $NAME
if [[ "$1" == "lldb" ]] ; then
    lldb test_queue
    rm -rf test_queue.dSYM
    rm test_queue
    exit
fi
if [[ "$1" == "leaks" ]] ; then
    leaks -atExit -- ./test_queue
    rm -rf test_queue.dSYM
    rm test_queue
    exit
fi
if [[ "$1" == "valgrind" ]] ; then
    valgrind ./test_queue
    rm -rf test_queue.dSYM
    rm test_queue
    exit
fi

./test_queue
rm test_queue
