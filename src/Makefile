test: LineParser.o Operation.o Token.o TokenParser.o Tree.o test.cpp
	g++ --std=c++17 test.cpp LineParser.o

LineParser.o: Token.o LineParser.cxx
	g++ --std=c++17 -c Lineparser.cxx Token.o

Operation.o: Token.o Operation.cxx 
	g++ --std=c++17 -c Operation.cxx Token.o

Token.o: Token.cxx
	g++ --std=c++17 -c Token.cxx 

TokenParser.o: Token.o Tree.o Operation.o TokenParser.cxx
	g++ --std=c++17 -c TokenParser.cxx Token.o Tree.o Operation.o

Tree.o: Operation.o Tree.cxx
	g++ --std=c++17 -c Tree.cxx Operation.o
