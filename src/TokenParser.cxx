#include <vector>
#include "Token.cxx"
#include "Operation.cxx"

std::vector<Op> TokenParser(std::vector <Token> TokenList){

	Token 			LastToken;
	Op 			*CurentOperation = nullptr;
	std::vector<Op> 	Result;

	for(auto curent : TokenList){
		if(curent.get_type() == Token::Type::Operation){
			if(LastToken.get_type() == Token::Type::Number){
				CurentOperation = new Op(curent);
				CurentOperation -> LeftNumber = LastToken; 
			}else{
				throw /*TODO*/;
			}
		}else if(curent.get_type() == Token::Type::Number){
			if(LastToken.get_type() == Token::Type::Number){
				throw /*TODO*/;
			}
			if(LastToken.get_type() == Token::Type::Operation){
				CurentOperation -> RightNumber = curent;
				Result.push_back(*CurentOperation);
				delete CurentOperation;
				CurentOperation = nullptr;
			}
		}
		LastToken = curent;		
	}
	if(CurentOperation != nullptr)
		throw /*TODO*/;
	return Result;
}

