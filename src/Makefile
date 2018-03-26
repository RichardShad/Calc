.PHONY: all clean

all: test

test: LineParser.o Operation.o Token.o TokenParser.o Tree.o TokenParser.o OperationListParser.o CalculateTree.o test.cxx
	g++ --std=c++17 test.cxx Token.o LineParser.o Operation.o TokenParser.o Tree.o OperationListParser.o CalculateTree.o 

LineParser.o: Token.o LineParser.cxx
	g++ --std=c++17 -c LineParser.cxx Token.o

OperationListParser.o: Operation.o Tree.o OperationListParser.cxx
	g++ --std=c++17 -c OperationListParser.cxx Operation.o Tree.o  

Operation.o: Token.o Operation.cxx 
	g++ --std=c++17 -c Operation.cxx Token.o 

Token.o: Token.cxx
	g++ --std=c++17 -c Token.cxx 

TokenParser.o: Token.o Operation.o TokenParser.cxx
	g++ --std=c++17 -c TokenParser.cxx Token.o Operation.o 

Tree.o: Operation.o Tree.cxx
	g++ --std=c++17 -c Tree.cxx Operation.o  

CalculateTree.o: Tree.o Token.o Operation.o CalculateTree.cxx
	g++ --std=c++17 -c CalculateTree.cxx Token.o Operation.o Tree.o 

clean: 
	rm ./*.o
