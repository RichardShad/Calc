#ifndef _CALCULATE_TREE_
#define _CALCULATE_TREE_

#include <functional>
#include "Tree.cxx"

int CalculateTree(node* tree){
	auto calc = [tree](){
		switch(std::get<Token::Operation>(tree -> Curent.Operation.get_value())){
			case Token::Operation::Addition:
				return (std::get<int>(tree -> Curent.LeftNumber.get_value()) + 
						std::get<int>(tree -> Curent.RightNumber.get_value()));

			case Token::Operation::Substraction:
				return (std::get<int>(tree -> Curent.LeftNumber.get_value()) - 
						std::get<int>(tree -> Curent.RightNumber.get_value()));

			case Token::Operation::Multiplication:
				return (std::get<int>(tree -> Curent.LeftNumber.get_value()) * 
						std::get<int>(tree -> Curent.RightNumber.get_value()));

			case Token::Operation::Division:
				return (std::get<int>(tree -> Curent.LeftNumber.get_value()) / 
						std::get<int>(tree -> Curent.RightNumber.get_value()));
			}
		};
	if(tree -> Left == nullptr && tree -> Right == nullptr)
		return calc();
	else{
		if(tree -> Left != nullptr){
			Token temp(CalculateTree(tree -> Left));
			tree -> Curent.LeftNumber = temp;
		}
		if(tree -> Right != nullptr){
			Token temp(CalculateTree(tree -> Right));
			tree -> Curent.RightNumber = temp;
		}
	}
	return calc();
}

#endif
