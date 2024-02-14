g++ stress.cpp -o stress.out
./stress.out > input.txt
g++ good.cpp -o good.out 
g++ bad.cpp -o bad.out 
./good.out < input.txt > good.txt
./bad.out < input.txt > bad.txt