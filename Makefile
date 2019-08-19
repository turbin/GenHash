all : GenHash

GenHash : main.cpp
	g++ -O2 -std=c++0x -g -Wall -o $@ $^

clean :
	rm GenHash