make clean
make
rm *.txt
cd synthethicN
rm *Solution*
cd ..
for f in $(ls synthethicN/*.txt)
do
    echo $f
    newf=$(basename -- "$f" .txt)
    for i in $(seq 1 500)
    do
        echo $i
        newName="${newf}SolutionHyper.txt"
        ./hipercor 7 < $f >> $newName
    done
    echo "==========================="
done

for f in $(ls synthethicN/*.txt)
do
    echo $f
    newf=$(basename -- "$f" .txt)
    for i in $(seq 1 500)
    do
        echo $i
        newName="${newf}SolutionRecord.txt"
        ./main 128 < $f >> $newName
    done
    echo "==========================="
done
mv *.txt synthethicN
make clean
