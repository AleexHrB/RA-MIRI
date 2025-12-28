make clean
make
rm *.txt
cd synthethicAlpha
rm *Solution*
cd ..
for f in $(ls synthethicAlpha/*.txt)
do
    echo $f
    newf=$(basename -- "$f" .txt)
    for i in $(seq 1 500)
    do
        echo $i
        newName="${newf}SolutionHyper.txt"
        ./hipercor 4 < $f >> $newName
    done
    echo "==========================="
done

for f in $(ls synthethicAlpha/*.txt)
do
    echo $f
    newf=$(basename -- "$f" .txt)
    for i in $(seq 1 500)
    do
        echo $i
        newName="${newf}SolutionRecord.txt"
        ./main 16 < $f >> $newName
    done
    echo "==========================="
done
mv *.txt synthethicAlpha
make clean
