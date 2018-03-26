#ifndef _TREE_
#define _TREE_

#include "Operation.cxx"

struct node{
	Op 	Curent;
	node* 		Left;
	node* 		Right;
	int		Position;

	node(){
		Left 	= nullptr;
		Right 	= nullptr;
	}
	node(Op operation, int position):
		Curent(operation),
		Position(position)	
	{
		Left 	= nullptr;
		Right 	= nullptr;
	}
	~node(){
		if(Left != nullptr)
			delete Left;
		if(Right != nullptr)
			delete Right;
	}
};

#endif
