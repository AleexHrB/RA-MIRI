
folder=$(pwd)
m=100
rm *.txt
cd ..
make 


for perc in 0.01 0.05 0.10 0.50 1.00
do
    for i in $(seq 1 200)
    do
        echo "Running $i"
        n=100
        while [ $n -le $((m*m)) ]
        do
            ./bins $n $m 1.00 $perc >> $folder/twoChoice$n-$perc.txt
            n=$((10*n))
        done
    done
done

make clean
