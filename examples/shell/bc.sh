#!/bin/bash

test_bc=$(echo "scale=2; 1.0 / 3.0" | bc -l)
echo "test_bc: $test_bc"
test_bc=$(echo "scale=2; 1.0 / 3.0" | bc)
echo "test_bc: $test_bc"
