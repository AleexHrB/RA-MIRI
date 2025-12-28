make clean
make
rm *.txt
for f in $(ls synthethicAlpha/*.txt)
do
    echo $f
    newf=$(basename -- "$f" .txt)
    for i in $(seq 1 500)
    do
        echo $i
        newName="${newf}Solution.txt"
        ./hipercor 4 < $f >> $newName
    done
    echo "==========================="
done
mv *.txt synthethicAlpha
make clean
