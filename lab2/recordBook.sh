make clean
make 
rm *.txt
f="datasets/dracula.txt"
echo $f
newf=$(basename "$f")
for i in $(seq 1 500)
do
    echo $i
    for b in $(seq 100 100 1200)
    do
        #./hipercor $b < $f >> $newf
        printf "$(./main $b < $f), " >> $newf
    done
    printf "$(./main $b < $f) \n" >> $newf
done

f="datasets/quijote.txt"
echo $f
newf=$(basename "$f")
for i in $(seq 1 500)
do
    echo $i
    for b in $(seq 100 100 1200)
    do
        #./hipercor $b < $f >> $newf
        printf "$(./main $b < $f), " >> $newf
    done
    printf "$(./main $b < $f) \n" >> $newf
done

mv *.txt recordFixedBook
make clean
