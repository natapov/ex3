make clean
echo "Compiling..."

echo "TEST A:"
make testA
./testA > tmp.out
echo "Correct <> Our ouput"
diff ./outputs/partA.txt tmp.out

echo "TEST B:"
make testB
./testB > tmp.out
echo "Correct <> Our ouput"
diff ./outputs/partB.txt tmp.out

echo "TEST C:"
make testC
./testC > tmp.out
echo "Correct <> Our ouput"
diff ./outputs/partC.txt tmp.out

echo "TEST E:"
make testE
./testE > tmp.out
echo "Correct <> Our ouput"
diff ./outputs/testE.txt tmp.out

echo "TEST L:"
make testL
./testL > tmp.out
echo "Correct <> Our ouput"
diff ./outputs/testL.txt tmp.out