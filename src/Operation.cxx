#ifndef _OPERATION_
#define _OPERATION_

#include "Token.cxx"

struct Op{
	Token Operation;
	Token LeftNumber;
	Token RightNumber;
	
	Op(){}
	Op(Token operation)
		:Operation(operation)
	{}
};

#endif
