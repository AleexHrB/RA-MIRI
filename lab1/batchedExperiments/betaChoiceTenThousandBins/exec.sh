
folder=$(pwd)
m=10000
rm *.txt
cd ..
make 

<<<<<<< HEAD
for perc in 0.01 0.05 0.10 0.50 1.00
=======
for beta in 0.25 0.5 0.75
>>>>>>> refs/remotes/origin/main
do
    for beta in 0.25 0.5 0.75
    do
        for i in $(seq 1 200)
        do
<<<<<<< HEAD
            echo "Running $i"
            n=100
            while [ $n -le $((m*m)) ]
            do
                ./bins $n $m $beta $perc >> $folder/betaChoice$n-$beta-$perc.txt
                n=$((10*n))
            done
=======
            ./bins $n $m $beta >> $folder/betaChoice$n-$beta.txt
            n=$((10*n))
>>>>>>> refs/remotes/origin/main
        done
    done
done
make clean
