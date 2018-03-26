#include <iostream>
#include "LineParser.cxx"
#include "TokenParser.cxx"
#include "OperationListParser.cxx"
#include "CalculateTree.cxx"
int main(){
	std::cout << CalculateTree(OperationListParser(TokenParser(LineParser("2+2*2+3*7")))) << std::endl;
}
