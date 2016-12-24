OBJS = main.o DecisionTree.o DecisionNode.o DataFileParser.o
CC = g++
DEBUG = -g
STD = c++11
CFLAGS = -Wall -c $(DEBUG) -std=$(STD)
LFLAGS = -Wall $(DEBUG) -std=$(STD)

algorithm = ID3Algorithm

default: $(OBJS) $(algorithm).o
	$(CC) $(LFLAGS) $(OBJS) $(algorithm).o -o main

main.o: main.cpp DataFileParser.o DecisionTree.o $(algorithm).o
	$(CC) $(CFLAGS) main.cpp

DecisionTree.o: DecisionTree.h DecisionTree.cpp DecisionNode.o
	$(CC) $(CFLAGS) DecisionTree.cpp

DecisionNode.o: DecisionNode.h DecisionNode.cpp
	$(CC) $(CFLAGS) DecisionNode.cpp

DataFileParser.o: DataFileParser.h DataFileParser.cpp
	$(CC) $(CFLAGS) DataFileParser.cpp

$(algorithm).o: $(algorithm).h $(algorithm).cpp
	$(CC) $(CFLAGS) $(algorithm).cpp

clean:
	rm *.o main
