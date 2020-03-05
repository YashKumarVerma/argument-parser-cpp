bin/makemake: bin/app.o  bin/parser.o  bin/rainbow.o 
	g++ --std=c++17 bin/app.o bin/parser.o bin/rainbow.o  -o bin/build

bin/app.o: source/app.cpp
	g++ --std=c++17 -c source/app.cpp -o bin/app.o

bin/parser.o: includes/parser/parser.cpp includes/parser/parser.h
	g++ --std=c++17 -c includes/parser/parser.cpp -o bin/parser.o

bin/rainbow.o: includes/rainbow/rainbow.cpp includes/rainbow/rainbow.h
	g++ --std=c++17 -c includes/rainbow/rainbow.cpp -o bin/rainbow.o

clean:
	rm -rf bin/*.o
