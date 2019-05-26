question-2: ./build/main.o
	g++ -g -o question-2 ./build/*.o

./build/main.o: ./src/main.cpp  ./build/Point.o ./build/Atom.o ./build/Cluster.o
	g++ -g -c -o ./build/main.o ./src/main.cpp

./build/Point.o: ./src/Point.cpp
	g++ -g -c -o ./build/Point.o ./src/Point.cpp

./build/Atom.o: ./src/Atom.cpp
	g++ -g -c -o ./build/Atom.o ./src/Atom.cpp

./build/Cluster.o: ./src/Cluster.cpp
	g++ -g -c -o ./build/Cluster.o ./src/Cluster.cpp

clean:
	rm -f question-2
	rm -f ./build/*
