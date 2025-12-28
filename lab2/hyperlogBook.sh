make clean
make hipercor
rm *.txt
f="datasets/dracula.txt"
echo $f
newf=$(basename "$f")
for i in $(seq 1 500)
do
    echo $i
    for b in $(seq 4 16)
    do
        #./hipercor $b < $f >> $newf
        printf "$(./hipercor $b < $f), "
    done
done
mv *.txt hyperlogFixedBook
make clean
