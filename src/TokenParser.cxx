#include "Tree.cxx"
#include "Token.cxx"
#include <vector>
#include <map>
#include <set>

node *TokenParser(std::vector <Token> tokenList){
	std::set <int> Priorities;
	std::map <int, std::vector<int>> elemntsBypriority; 
	std::map <node*, int> indexMap;

	for(auto it = tokenList.begin(); it < tokenList.end(); it++){
		Priorities.insert(it -> get_priority());
		elemntsBypriority[it -> get_priority()].push_back(it - tokenList.begin());
	}
}
		 
