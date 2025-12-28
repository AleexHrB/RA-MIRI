#!/bin/bash

alpha=1.25
N=100000
n=(100 200 500 750 1000)
make

for nMin in "${n[@]}"; do
    echo "Generating data for alpha=$alph ..."

    while true; do
        ./generateData "$nMin" "$N" "$alpha" > syntData.txt

        # Count distinct numeric elements:
        distinct=$(sort -n syntData.txt | uniq | wc -l)

        if [[ "$distinct" -eq "$nMin" ]]; then
            echo "Success: $distinct distinct values found."
            mv syntData.txt syntData$nMin.txt
            break
        else
            echo "With $alpha only $distinct distinct values found. Regenerating..."
        fi
    done

done

make clean
