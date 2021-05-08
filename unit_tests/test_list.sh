#!/bin/bash
CC=clang++
SRCS=test_list.cpp
NAME=test_list
$CC $SRCS -g -o $NAME
if [[ "$1" == "lldb" ]] ; then
    lldb test_list
    rm -rf test_list.dSYM
    rm test_list
fi
./test_list
rm test_list