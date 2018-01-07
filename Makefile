target:
	g++ ./split.cpp ./libNLPIR.so -lpthread -Wall -Wunused -O3 -DOS_LINUX
clean:
	rm a.out
