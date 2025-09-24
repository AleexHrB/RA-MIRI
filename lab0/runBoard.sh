#!/bin/bash
make
# Define vectors of values for n and m
n_values=(100 500 1000 1500)
m_values=(1000)

# Loop through all combinations
for n in "${n_values[@]}"; do
    for m in "${m_values[@]}"; do
        echo "Running: ./galton $n $m -> result${n}_${m}.csv"
        ./galton "$n" "$m" > "result${n}_${m}.csv"
    done
done

make clean
