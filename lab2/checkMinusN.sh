make clean
make
rm *.txt
for f in $(ls synthethicn/*.txt)
do
    echo $f
    newf=$(basename -- "$f" .txt)
    for i in $(seq 1 500)
    do
        echo $i
        newName="${newf}Solution.txt"
        ./hipercor 5 < $f >> $newName
    done
    echo "==========================="
done
mv *.txt synthethicn
make clean
