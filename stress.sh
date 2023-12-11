g++ stress.cpp -o stress.out
./stress.out > input.txt
g++ fast.cpp -o fast.out 
g++ slow.cpp -o slow.out 
./fast.out < input.txt > fast.txt
./slow.out < input.txt > slow.txt