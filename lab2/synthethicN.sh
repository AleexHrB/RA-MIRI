#!/bin/bash

alpha=1.25
N=(50000 75000 100000 125000 150000 175000 200000)
n=700
make

for nCaps in "${N[@]}"; do
    echo "Generating data for N=$nCaps ..."

    while true; do
        ./generateData "$n" "$nCaps" "$alpha" > syntData.txt

        # Count distinct numeric elements:
        distinct=$(sort -n syntData.txt | uniq | wc -l)

        if [[ "$distinct" -eq "$n" ]]; then
            echo "Success: $distinct distinct values found."
            mv syntData.txt syntData$nCaps.txt
            break
        else
            echo "With $nCaps only $distinct distinct values found. Regenerating..."
        fi
    done

done

make clean
