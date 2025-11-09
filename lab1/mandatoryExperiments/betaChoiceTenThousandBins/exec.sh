
folder=$(pwd)
m=10000
rm *.txt
cd ..
make 

for beta in 0.25 0.5 0.75
do
    for i in $(seq 1 1000)
    do
        echo "Running $i"
        n=10
        while [ $n -le $((m*m)) ]
        do
            ./bins $n $m $beta >> $folder/betaChoice$n-$beta.txt
            n=$((10*n))
        done
    done
done
make clean
