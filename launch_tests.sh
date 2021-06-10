#!/bin/bash

echo "LIST"
cd ./unit_tests && ./test_list.sh && cd ..
echo "VECTOR"
cd ./unit_tests && ./test_vector.sh && cd ..
echo "MAP"
cd ./unit_tests && ./test_map.sh && cd ..
echo "STACK"
cd ./unit_tests && ./test_stack.sh && cd ..
echo "QUEUE"
cd ./unit_tests && ./test_queue.sh && cd ..

