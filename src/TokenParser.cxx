#include "Tree.cxx"
#include "Operation.cxx"
#include "Token.cxx"
#include <vector>
#include <map>
#include <set>

node *TokenParser(std::vector <Token> tokenList){
	
	node*					result;
	std::set <int>				Priorities;
	std::map <int, std::vector<int>>	elemntsByPriority; 
	std::map <node*, int>			indexMap;
	std::vector <Op>			operationList;
	Token					lastToken;
	Op*					curentOperation		= nullptr;

	for(auto curent : tokenList){
		if(curent.get_type() == Token::Type::Operation){
			if(lastToken.get_type() == Token::Type::Number){
				curentOperation = new Op(curent);
				curentOperation -> LeftNumber = lastToken;
			}else{
				throw /*TODO*/;
			}
		else if(curent.get_type() == Token::Type::Number){
			if(lastToken.get_type() == Token::Type::Operation){
				curentOperation -> RightNumber = curent;
				operationList.push_back(*curentOperation);
				delete curentOperation;
			}
		}
		lastToken = curent;
	}	
	for(auto iterator = operationList.begin(); iterator < operationList.end(); iterator++){
		Priorities.insert(iterator -> Operation.get_priority());
		elemntsByPriority[Operation.get_priority()].push_back(iterator - operationList.begin());
	}
	for(auto curentPriority : Priorities){
		for(auto element = elemntsBypriority[curentPriority].rbegin(); element < elemntsBypriority[curentPriority].rend(); element++){
			node *temp = new node(element);
			if(result != nullptr){
				for(node *inserter = result;;){
					if(indexMap[inserter] < )
				}
			}
			
		}
	} 
}
		 
