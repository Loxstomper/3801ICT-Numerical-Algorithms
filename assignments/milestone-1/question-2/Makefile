question-2: main.o Record.o Point.o
	g++ -o question-2 ./build/*.o

main.o: ./src/main.cpp Point.o Record.o
	g++ -c ./src/main.cpp -o ./build/main.o

Record.o: ./src/Record.cpp Point.o 
	g++ -c ./src/Record.cpp -lm -o ./build/Record.o

Point.o: ./src/Point.cpp
	g++ -c ./src/Point.cpp -o ./build/Point.o

clean:
	rm question-2 ./build/*.o 