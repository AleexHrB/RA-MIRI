
folder="oneChoiceHundredBins"
m=100
rm *.txt
cd ..
make 

for i in $(seq 1 1000)
do
    n=10
    while [ $n -le $((m*m)) ]
    do
        ./bins $n $m 0.00 >> $folder/oneChoice$n.txt
        n=$((10*n))
    done
done

make clean
