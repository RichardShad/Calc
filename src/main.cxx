#include <iostream>
#include <string>
#include <array>
#include "LineParser.cxx"
#include "TokenParser.cxx"
#include "OperationListParser.cxx"
#include "CalculateTree.cxx"

int main(){
	try{
		std::array <char, 51> buf;
		std::cin.getline(&buf[0],50);	
		std::cout << CalculateTree(OperationListParser(TokenParser(LineParser(buf.data())))) << std::endl;
	}catch(...){
		std::cout << "Something went wrong!" << std::endl;
	}
}
