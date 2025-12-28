#!/bin/bash

alpha=(0 0.5 1 1.5 2 2.5 3)
N=100000
n=45
make

for alph in "${alpha[@]}"; do
    echo "Generating data for alpha=$alph ..."

    while true; do
        ./generateData "$n" "$N" "$alph" > syntData.txt

        # Count distinct numeric elements:
        distinct=$(sort -n syntData.txt | uniq | wc -l)

        if [[ "$distinct" -eq "$n" ]]; then
            echo "Success: $distinct distinct values found."
            mv syntData.txt syntData$alph.txt
            break
        else
            echo "With $alph only $distinct distinct values found. Regenerating..."
        fi
    done

done

make clean
