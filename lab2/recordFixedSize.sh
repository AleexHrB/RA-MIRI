make clean
make
rm *.txt
for f in $(ls datasets/*.txt)
do
    echo $f
    newf=$(basename "$f")
    for i in $(seq 1 500)
    do
        echo $i
        ./main 256 < $f >> $newf
    done
    echo "==========================="
done
mv *.txt recordBench
make clean
