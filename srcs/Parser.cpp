#include "../inc/Parser.hpp"

Parser::Parser() {
	_error = false;
}

Parser::Parser(Parser const &rhs) {
	*this = rhs;
}

Parser::~Parser() {}

void	Parser::parser(std::vector<Token> token) {
	Interpreter inter;
	Lexer l;
	// try {
		for(i = 0; i < token.size(); i++) {
			validation_size(token[i].type, token[i].value);
			if (token[i].operation == Push) {
				inter.push(token[i].type, token[i].value, token[i].dt);
			}
			else if (token[i].operation == Assert) {
				inter.assert(token[i].type, token[i].value);
			}
			else if (token[i].operation == Pop) {
				inter.pop();
			}
			else if (token[i].operation == Dump) {
				inter.dump();
			}
			else if (token[i].operation == Print) {
				inter.print();
			}
			else if (token[i].operation == Info) {
				inter.info();
			}
			else if (token[i].operation == Add || token[i].operation == Sub || 
					token[i].operation == Mul || token[i].operation == Div || 
					token[i].operation == Mod || token[i].operation == Pow) {
				inter.operations(token[i].operation);
			}
			else if (token[i].operation == Sqrt) {
				inter.ssqrt();
			}
			else if (token[i].operation == Min) {
				inter.min();
			}
			else if (token[i].operation == Max) {
				inter.max();
			}
			else if (token[i].operation == Clear) {
				inter.clear();
			}
			else if (token[i].operation == Exit) {
				exit(0);
			}
			else if (token[i].operation == Stop) {
				inter.stop();
			}
		}
	}
	// catch(std::exception &e) {
	// 	std::cout << "Parser error" << std::endl;
	// 	//exit(0);
	// }
//}

void	Parser::validation_size(eOperandType type, std::string value) {
	try {	
		if (type == Int8) {
			long long int int8 = std::stol(value);
			if (int8 < -128 || int8 > 127)
				throw OverflowException(value);
		}
		else if (type == Int16) {
			long long int int16 = std::stol(value);
			if (int16 < -327683 || int16 > 32767)
				throw OverflowException(value);
		}
		else if (type == Int32) {
			long long int int32 = std::stol(value);
			if (int32 < -2147483648 || int32 > 2147483647)
				throw OverflowException(value);
		}
		else if (type == Float) {
			try {
				std::stof(value);
			}
			catch (std::exception &e) {
				_error = true;
				std::cout << "Error: Line: " << i + 1 << ". OverflowException [" << value << "]"<< e.what() << std::endl;
			}
		}
		else if (type == Double) {
			try {
				std::stod(value);
			}
			catch (std::exception &e) {
				_error = true;
				std::cout << "Error: Line: " << i + 1 << ". OverflowException [" << value << "]"<< e.what() << std::endl;
			}
		}
	}
	catch (OverflowException &e) {
		std::cout << "Error: Line: " << i + 1 <<  " Overflow on a value [" << e.what() << "] " << std::endl;
		//exit(0);
	}
}
