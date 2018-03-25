#ifndef _TREE_
#define _TREE_

#include "Operation.cxx"

struct node{
	Op 	Curent;
	node* 	Left;
	node* 	Right;

	node(){
		Left 	= nullptr;
		Right 	= nullptr;
	}
	node(Op operation):Curent(operation){
		Left 	= nullptr;
		Right 	= nullptr;
	};

#endif
