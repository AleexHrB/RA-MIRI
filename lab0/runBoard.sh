#!/bin/bash
make
# Define vectors of values for n and m
n_values=(10 25 50 100)
m_values=(50)

# Loop through all combinations
for n in "${n_values[@]}"; do
    for m in "${m_values[@]}"; do
        echo "Running: ./galton $n $m -> result${n}_${m}.csv"
        ./galton "$n" "$m" > "result${n}_${m}.csv"
    done
done

make clean
