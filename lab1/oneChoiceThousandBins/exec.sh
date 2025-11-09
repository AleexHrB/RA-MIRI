
folder="oneChoiceThousandBins"
m=1000
rm *.txt
cd ..
make 

for i in $(seq 1 1000)
do
    echo "Running $i iteration"
    n=10
    while [ $n -le $((m*m)) ]
    do
        ./bins $n $m 0.00 >> $folder/oneChoice$n.txt
        n=$((10*n))
    done
done

make clean
