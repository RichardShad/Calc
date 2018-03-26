#ifndef _OPERATION_LIST_PARSER_
#define _OPERATION_LIST_PARSER_

#include <vector>
#include <map>
#include <set>
#include "Tree.cxx"

node *OperationListParser(std::vector<Op> OperationList){
	
	node*					result			= nullptr;
	std::map<int, std::vector<int>>		IndexingByPriority;
	std::set<int>				Priority;

	for(auto it = OperationList.begin(); it < OperationList.end(); it++){
		Priority.insert(it -> Operation.get_priority());
		IndexingByPriority[it -> Operation.get_priority()].push_back(it - OperationList.begin());
	}

	for(auto CurentPriority : Priority){
		for(auto it = IndexingByPriority[CurentPriority].rbegin(); it < IndexingByPriority[CurentPriority].rend(); it++){
			if(result != nullptr)
				result -> insert(new node(OperationList[*it], *it));
			else
				result = new node(OperationList[*it], *it);
		}
	}
	return result;
}

#endif
