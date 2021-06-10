#!/bin/bash
CC=clang++
SRCS=test_stack.cpp
NAME=test_stack
$CC $SRCS -g -o $NAME
if [[ "$1" == "lldb" ]] ; then
    lldb test_stack
    rm -rf test_stack.dSYM
    rm test_stack
    exit
fi
if [[ "$1" == "leaks" ]] ; then
    leaks -atExit -- ./test_stack
    rm -rf test_stack.dSYM
    rm test_stack
    exit
fi
if [[ "$1" == "valgrind" ]] ; then
    valgrind ./test_stack
    rm -rf test_stack.dSYM
    rm test_stack
    exit
fi

./test_stack
rm test_stack
