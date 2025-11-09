
folder=$(pwd)
m=10000
rm *.txt
cd ..
make 

for i in $(seq 1 1000)
do
    echo "Running $i"
    n=10
    while [ $n -le $((m*m)) ]
    do
        ./bins $n $m 1.00 >> $folder/twoChoice$n.txt
        n=$((10*n))
    done
done

make clean
