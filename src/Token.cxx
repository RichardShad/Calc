#ifndef _TOKEN_
#define _TOKEN_


#include <variant>
#include <ostream>

class Token{
	public:
		enum class Type{
			Number, Operation, Empty
		};
		enum class Operation{
			Addition, Substraction, Multiplication, Division
		};
		Token(){
			type = Type::Empty;
		}
		Token(int number){
			type = Type::Number;
			value = number;
		}
		Token(char op, int additional_priority = 0){
			type = Type::Operation;
			switch(op){
				case '+':
					value = Operation::Addition;
					priority = 0 + additional_priority;
					break;
				case '-':
					value = Operation::Substraction;
					priority = 0 + additional_priority;
					break;
				case '*':
					value = Operation::Multiplication;
					priority = 1 + additional_priority;
					break;
				case '/':
					value = Operation::Division;
					priority = 1 + additional_priority;
					break;
			}
		}
		Type get_type() const {
			return type;
		}
		std::variant <int, Operation> get_value() const {
			return value;
		}
		int get_priority() const {
			return priority;
		}
	private:
		Type type;
		std::variant <int, Operation> value;
		int priority;
};

std::ostream &operator<<(std::ostream &os, const Token &tk){
	if(tk.get_type()==Token::Type::Number){
		try{
			os << "Number: \"" << std::get<int>(tk.get_value()) << "\"." << std::endl;
		}catch(const std::bad_variant_access&) {
			os << "Error!" << std::endl;
		}
	}
	else if(tk.get_type()==Token::Type::Empty) os << "Empty token." << std::endl;
	else if(tk.get_type()==Token::Type::Operation){
		try{
			os << "Operation: \"";
			switch(std::get<Token::Operation>(tk.get_value())){
				case Token::Operation::Addition:
					os << '+';
					break;
				case Token::Operation::Substraction:
					os << '-';
					break;
				case Token::Operation::Multiplication:
					os << '*';
					break;
				case Token::Operation::Division:
					os << '/';
					break;
			}
			os << "\". Priority: " << tk.get_priority() << '.' << std::endl;
		}catch(const std::bad_variant_access&){
			os << "Error!" << std::endl;
		}
	}
	return os;
}

#endif
