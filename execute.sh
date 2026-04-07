#!/bin/bash

# Default values
COUNT=${1:-1000}     # first argument or default 1000
RUNS=${2:-100}       # second argument or default 100

echo "Generating $COUNT random numbers..."
echo "Running ./selection_sort $RUNS times..."

# Generate random integers (positive + negative)
numbers=()
for ((i=0; i<COUNT; i++)); do
    n=$((RANDOM * RANDOM % 200001 - 100000))
    numbers+=("$n")
done

# Convert array to argument string
args="${numbers[*]}"

# Run multiple times with same input
for ((run=1; run<=RUNS; run++)); do
    echo "Run #$run"
    ./selection_sort $args
done