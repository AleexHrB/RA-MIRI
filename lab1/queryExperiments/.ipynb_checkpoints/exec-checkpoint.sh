
folder=$(pwd)
m=100
rm *.txt
cd ..
make 


for k in 1 2
do
    for i in $(seq 1 1000)
    do
        echo "Running $i"
        n=10
        while [ $n -le $((m*m)) ]
        do
            ./bins $n $m $k >> $folder/twoChoice$n.txt
            n=$((10*n))
        done
    done
done

make clean
