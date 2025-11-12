
folder=$(pwd)
m=100
rm *.txt
cd ..
make 

for perc in 0.01 0.05 0.10 0.50 1.00
do
    for beta in 0.25 0.5 0.75
    do
        for i in $(seq 1 200)
        do
            echo "Running $i"
            n=100
            while [ $n -le $((m*m)) ]
            do
                ./bins $n $m $beta $perc >> $folder/betaChoice$n-$beta-$perc.txt
                n=$((10*n))
            done
        done
    done
done
make clean
