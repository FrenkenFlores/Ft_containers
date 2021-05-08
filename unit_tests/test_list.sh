#!/bin/bash
CC=clang++
SRCS=test_list.cpp
NAME=test_list
$CC $SRCS -o $NAME
./test_list
rm test_list
