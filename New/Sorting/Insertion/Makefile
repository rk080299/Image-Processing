all: hello
	./hello

hello: insertion.o
	g++ insertion.o -o hello

insertion.o: insertion.cpp
	g++ -c insertion.cpp
clean:
	rm -rf *o hello
