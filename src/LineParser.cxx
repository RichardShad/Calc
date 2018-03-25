#ifndef _LINE_PARSER_
#define _LINE_PARSER_

#include <vector>
#include <string>
#include <iostream>
#include "Token.cxx"

std::vector<Token> LineParser(std::string raw){
	int add_prior = 0;
	std::vector <Token> result;
	std::string temp_number = "";
	
	for(auto curent:raw){
		if(curent < '0' || curent > '9'){
			if(temp_number != ""){
				try{
					int num = std::stoi(temp_number);
					Token *temp = new Token(num);
					result.push_back(*temp);
					delete temp;
					temp_number = "";
				}catch(...){
					std::cout << "Error";
				}
			}
		}else{
			temp_number += curent;
		}
		switch(curent){
			case '+': case '-': case '*': case '/':{
				Token *temp = new Token(curent, add_prior);
				result.push_back(*temp);
				delete temp;
				break;
			}
			case '(':{
				add_prior++;
				break;
			}
			case ')':{
				add_prior--;
				break;
			}
		}
	}
	if(temp_number != ""){
		int num = std::stoi(temp_number);
		Token *temp = new Token(num);
		result.push_back(*temp);
		delete temp;
		temp_number = "";
	}
	return result;
}

#endif
