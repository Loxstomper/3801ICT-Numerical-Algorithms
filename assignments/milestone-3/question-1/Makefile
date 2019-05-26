question-1: ./build/main.o
	g++ -o question-1 ./build/*.o

./build/main.o: ./src/main.cpp ./build/Point.o
	g++ -c -o ./build/main.o ./src/main.cpp

./build/Point.o: ./src/Point.cpp
	g++ -c -o ./build/Point.o ./src/Point.cpp

graphs: ./question-1
	./question-1 | python3 ./graphs.py

clean:
	rm -f question-1
	rm -f ./build/*